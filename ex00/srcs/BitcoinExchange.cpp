/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:17:38 by erpascua          #+#    #+#             */
/*   Updated: 2026/04/01 02:18:57 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy)
{
	*this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& cpy)
{
	if (this != &cpy)
	{
		_data	= cpy._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/* ************************************************************************** */
// 																			  //
// 						   			GETTERS									  //
//																	 		  //
/* ************************************************************************** */

const std::map<std::string, float>& BitcoinExchange::getData() const
{
	return (_data);
}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTION								  //
//																	 		  //
/* ************************************************************************** */

bool	BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream	db;
	
	db.open(filename.c_str(), std::ifstream::in);
	if (!db)
	{
		std::cerr << "Error: cannot open database file: " << filename << std::endl;
		return (false);
	}

	std::string		line;
	if (!std::getline(db, line))
	{
		std::cerr << "Error: empty database file." << std::endl;
		return (false);
	}

	while (std::getline(db, line))
	{
		std::stringstream	ss;
		std::string			date;
		float				exchangeRate;

		ss << line;
		std::getline(ss, date, ',');
		if (!isValidDate(date))
		{
			std::cerr << "Error: Invalid date in database => " << date << std::endl;
			continue ;
		}
		ss >> exchangeRate;

		_data[date] = exchangeRate;
	}
	db.close();
	return (true);
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream	input;
	
	input.open(filename.c_str(), std::ifstream::in);
	if (!input)
	{
		std::cerr << "Error: cannot open input file: " << filename << std::endl;
		return ;
	}

	std::string		line;
	if (!std::getline(input, line))
	{
		std::cerr << "Error: empty input file." << std::endl;
		return ;
	}
	
	while(std::getline(input, line))
	{
		std::stringstream	ss;
		std::string			date;
		char				sep;
		float				value;
		bool				isValid = true;
		
		ss << line;
		if (!(ss >> date >> sep >> value) || sep != '|')
		{
			std::cerr << "Error: Bad input => " << line << std::endl;
			continue ;
		}
		ss >> std::ws;
		if (!ss.eof())
		{
			std::cerr << "Error: Bad input => " << line << std::endl;
			continue ;
		}

		if (!isValidDate(date))
		{
			std::cerr << "Error: Bad input => " << date << std::endl;
			isValid = false;
			continue ;
		}
		ss >> value;
		if (!isValidValue(value))
		{
			isValid = false;
			continue ;
		}

		if (isValid)
			std::cout << date << " => " << value << " = " << value * getRateForDate(date) << std::endl;
	}
	input.close();
}

bool	BitcoinExchange::isValidDate(const std::string&date) const
{
	std::stringstream	ss;
	int		year;
	int		month;
	int		day;

	if (date.length() != 10)
		return (false);

	if (date[4] != '-' || date[7] != '-')
		return (false);
	
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(date[i]))
			return (false);
	}

	year	= std::atoi(date.substr(0, 4).c_str());
	if (year < 2009)
		return (false);
	month	= std::atoi(date.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		return (false);

	day		= std::atoi(date.substr(8, 2).c_str());
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31))
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
		return (false);
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day < 1 || day > 29)
				return (false);
		}
		else
		{
			if (day < 1 || day > 28)
				return (false);
		}
	}
	return (true);
}

bool	BitcoinExchange::isValidValue(const float value) const
{
	if (value < 0)
	{
		std::cerr << "Error: Not a positive number." << std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cerr << "Error: Too large a number." << std::endl;
		return (false);
	}
	return (true);
}

float	BitcoinExchange::getRateForDate(const std::string& date) const
{
	if (_data.empty())
		return (0.0f);

	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	
	if (it == _data.end())
		return (--it)->second;
	
	if (it->first == date)
		return (it->second);
	
	if (it == _data.begin())
		return (0.0f);

	return ((--it)->second);
}
