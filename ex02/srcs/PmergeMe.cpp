/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 02:42:18 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/25 03:49:11 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ************************************************************************** */
// 																			  //
// 						   	  Orthodox Canonical Form						  //
//																	 		  //
/* ************************************************************************** */

PmergeMe::PmergeMe(): _nbInts(0), _isOdd(false), _oddValue(0), _vLaps(0), _dLaps(0) {}

PmergeMe::PmergeMe(const PmergeMe& cpy)
{
	*this = cpy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& cpy)
{
	if (this != &cpy)
	{
		_vector = cpy._vector;
		_deque = cpy._deque;
		_nbInts = cpy._nbInts;
		_isOdd = cpy._isOdd;
		_oddValue = cpy._oddValue;
		_vLaps = cpy._vLaps;
		_dLaps = cpy._dLaps;
		_vPairs = cpy._vPairs;
		_dPairs = cpy._dPairs;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

unsigned int	PmergeMe::getNbInts() const
{
	return (_nbInts);
}

double	PmergeMe::getVLaps() const
{
	return (_vLaps);
}

double	PmergeMe::getDLaps() const
{
	return (_dLaps);
}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

void	PmergeMe::inputToContainer(int ac, char **av)
{
	_vector.clear();
	_deque.clear();
	_nbInts = 0;
	for (int i = 1; i < ac; i++)
	{
		int tmp = std::atoi(av[i]);
		
		_vector.push_back(tmp);
		_deque.push_back(tmp);
		_nbInts++;
	}
}

void	PmergeMe::printNumbers() const
{
	for (std::vector<int>::const_iterator itV = _vector.begin(); itV != _vector.end(); ++itV)
	{
		std::cout << *itV;
		if (itV + 1 != _vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::globalSort()
{
	_isOdd = false;
	if (_nbInts %2 != 0)
	{
		_isOdd = true;
		_oddValue = _vector.back();
	}
	sortVector();
	sortDeque();
}

void	PmergeMe::sortVector()
{
	clock_t	start	=	clock();
	// std::sort(_vector.begin(), _vector.end());
	
	_vPairs.clear();
	for (std::vector<int>::const_iterator itV = _vector.begin(); itV < _vector.end() - 1; itV += 2)
	{
		if (*itV < *(itV + 1))
			_vPairs.push_back(std::make_pair(*itV, *(itV + 1)));
		else
			_vPairs.push_back(std::make_pair(*(itV + 1), *itV));
	}

	for (size_t i = 0; i < _vPairs.size(); i++)
	{
		for (size_t j = 0; j + 1 < _vPairs.size() - i; j++)
		{
			if (_vPairs[j].second > _vPairs[j + 1].second)
				std::swap(_vPairs[j], _vPairs[j + 1]);
		}
	}
	
	_vector.clear();
	for (std::vector<std::pair<int, int> >::iterator itVP = _vPairs.begin(); itVP != _vPairs.end(); itVP++)
		_vector.push_back(itVP->second);
	for (std::vector<std::pair<int, int> >::iterator itVP = _vPairs.begin(); itVP != _vPairs.end(); itVP++)
	{
		std::vector<int>::iterator pos = std::lower_bound(_vector.begin(), _vector.end(), itVP->first);
		_vector.insert(pos, itVP->first);
	}
	if (_isOdd)
	{
		std::vector<int>::iterator pos = std::lower_bound(_vector.begin(), _vector.end(), _oddValue);
		_vector.insert(pos, _oddValue);
	}
	
		
	clock_t	end		= clock();
	_vLaps	= static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

void	PmergeMe::sortDeque()
{
	clock_t	start	=	clock();
	// std::sort(_deque.begin(), _deque.end());

	_dPairs.clear();
	for (std::deque<int>::const_iterator itD = _deque.begin(); itD < _deque.end() - 1; itD += 2)
	{
		if (*itD < *(itD + 1))
			_dPairs.push_back(std::make_pair(*itD, *(itD + 1)));
		else
			_dPairs.push_back(std::make_pair(*(itD + 1), *itD));
	}

	for (size_t i = 0; i < _dPairs.size(); i++)
	{
		for (size_t j = 0; j + 1 < _dPairs.size() - i; j++)
		{
			if (_dPairs[j].second > _dPairs[j + 1].second)
				std::swap(_dPairs[j], _dPairs[j + 1]);
		}
	}
		
	_deque.clear();
	for (std::deque<std::pair<int, int> >::iterator itDP = _dPairs.begin(); itDP != _dPairs.end(); itDP++)
		_deque.push_back(itDP->second);
	for (std::deque<std::pair<int, int> >::iterator itDP = _dPairs.begin(); itDP != _dPairs.end(); itDP++)
	{
		std::deque<int>::iterator pos = std::lower_bound(_deque.begin(), _deque.end(), itDP->first);
		_deque.insert(pos, itDP->first);
	}
	if (_isOdd)
	{
		std::deque<int>::iterator pos = std::lower_bound(_deque.begin(), _deque.end(), _oddValue);
		_deque.insert(pos, _oddValue);
	}
	
	clock_t	end		= clock();
	_dLaps	= static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}


/* ************************************************************************** */
// 																			  //
// 						   		EXTERNAL FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

bool areValidInputs(int ac, char **av)
{
	if (ac < 2)
		return (std::cerr << "Error: Wrong number of arguments" << std::endl, false);
	
	for (int i = 1; i < ac; i++)
	{
		if (std::strlen(av[i]) == 0)
			return (std::cerr << "Error: empty inputs are not allowed" << std::endl, false);

		size_t tmpLen = std::strlen(av[i]);
		for (size_t j = 0; j < tmpLen; j++)
		{
			if (!std::isdigit(static_cast<unsigned char>(av[i][j])))
				return (std::cerr << "Error: " << av[i] << " is not a valid input" << std::endl, false);
		}

		long tmpLong = std::atol(av[i]);
		if (tmpLong <= 0 || tmpLong > INT_MAX)
			return (std::cerr << "Error: " << av[i] << " is not a valid number" << std::endl, false);
	}
	return (true);
}

/* ************************************************************************** */
// 																			  //
// 						   				Debug								  //
//																	 		  //
/* ************************************************************************** */

void	PmergeMe::printContainer() const
{
	std::cout << "<-- Vector -->" << std::endl;
	for (std::vector<int>::const_iterator itV = _vector.begin(); itV != _vector.end(); itV++)
		std::cout << *itV << std::endl;

	std::cout << "\n<-- Deque -->" << std::endl;
	for (std::deque<int>::const_iterator itD = _deque.begin(); itD != _deque.end(); itD++)
		std::cout << *itD << std::endl;
}

void	PmergeMe::printPairs() const
{
	std::cout << "<-- Vector Pairs -->" << std::endl;
	for (std::vector<std::pair<int, int> >::const_iterator itVP = _vPairs.begin(); itVP != _vPairs.end(); itVP++)
		std::cout << itVP->first << " | " << itVP->second << std::endl;
	if (_nbInts % 2 != 0)
		std::cout << _oddValue << std::endl;

	std::cout << "\n<-- Deque Pairs -->" << std::endl;
	for (std::deque<std::pair<int, int> >::const_iterator itDP = _dPairs.begin(); itDP != _dPairs.end(); itDP++)
		std::cout << itDP->first << " | " << itDP->second << std::endl;
	if (_nbInts % 2 != 0)
		std::cout << _oddValue << std::endl;
}
