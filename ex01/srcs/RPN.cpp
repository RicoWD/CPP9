/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:23:28 by erpascua          #+#    #+#             */
/*   Updated: 2026/04/15 14:26:13 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

void	RPN::calc(std::string op)
{
	std::list<int>		lst;
	std::istringstream	iss(op);
	std::string			token;
	long				iMax = INT_MAX;
	long				iMin = INT_MIN;

	while (iss >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			lst.push_back(std::atoi(token.c_str()));
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (lst.size() < 2)
			{
				std::cerr << "Error: Not enough operands" << std::endl;
				return ;
			}
			int b = lst.back();
			lst.pop_back();
			int a = lst.back();
			lst.pop_back();
			long result;

			if (token == "+")
				result = static_cast<long>(a) + static_cast<long>(b);
			else if (token == "-")
				result = static_cast<long>(a) - static_cast<long>(b);
			else if (token == "*")
				result = static_cast<long>(a) * static_cast<long>(b);
			else
			{
				if (b == 0)
				{
					std::cerr << "Error: Division by zero not allowed" << std::endl;
					return ;
				}
				result = static_cast<long>(a) / static_cast<long>(b);
			}

			if (result > iMax || result < iMin)
			{
				std::cerr << "Error: Integer overflow" << std::endl;
				return ;
			}
			lst.push_back(static_cast<int>(result));
		}
		else
		{
			std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
			return ;
		}
	}
	if (lst.size() != 1)
	{
		std::cerr << "Error: Invalid expression" << std::endl;
		return ;
	}
	std::cout << lst.back() << std::endl;
}


/* ************************************************************************** */
// 																			  //
// 						   			EXCEPTION								  //
//																	 		  //
/* ************************************************************************** */

const char *RPN::NotEnoughOperandException::what() const throw()
{
	return ("Not Enough Operand Exception");
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return ("Division By Zero Exception");
}

const char *RPN::InvalideTokenException::what() const throw()
{
	return ("Invalide Token Exception");
}

const char *RPN::InvalideExpressionException::what() const throw()
{
	return ("Invalide Expression Exception");
}
