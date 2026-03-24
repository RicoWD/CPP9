/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 02:42:18 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/24 03:24:07 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ************************************************************************** */
// 																			  //
// 						   	  Orthodox Canonical Form						  //
//																	 		  //
/* ************************************************************************** */

PmergeMe::PmergeMe(): _nbInts(0), _oddValue(0), _vLaps(0), _dLaps(0) {}

PmergeMe::PmergeMe(const PmergeMe& cpy)
{
	*this = cpy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& cpy)
{
	if (this != &cpy)
	{
		_vectorInt = cpy._vectorInt;
		_dequeInt = cpy._dequeInt;
		_nbInts = cpy._nbInts;
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
	for (int i = 1; i < ac; i++)
	{
		int tmp = std::atoi(av[i]);
		
		_vectorInt.push_back(tmp);
		_dequeInt.push_back(tmp);
		_nbInts++;
	}
}

void	PmergeMe::printNumbers() const
{
	for (std::vector<int>::const_iterator itV = _vectorInt.begin(); itV != _vectorInt.end(); ++itV)
	{
		std::cout << *itV;
		if (itV + 1 != _vectorInt.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::globalSort()
{
	if (_nbInts %2 != 0)
		_oddValue = _vectorInt.back();
	sortVector();
	sortDeque();
}

void	PmergeMe::sortVector()
{
	clock_t	start	=	clock();
	// std::sort(_vectorInt.begin(), _vectorInt.end());
	
	_vPairs.clear();
	for (std::vector<int>::const_iterator itV = _vectorInt.begin(); itV + 1 != _vectorInt.end(); itV += 2)
	{
		if (*itV < *(itV + 1))
			_vPairs.push_back(std::make_pair(*itV, *(itV + 1)));
		else
			_vPairs.push_back(std::make_pair(*(itV + 1), *itV));
	}

	// _vectorSorted.clear();
	// for (std::vector<std::pair<int, int> >::iterator itVP = _vPairs.begin(); itVP != _vPairs.end(); itVP++)
	// {
	// 	if (itVP->second > (itVP + 1)->second)
	// 		std::swap(*itVP, *(itVP + 1));
		
	// 	_vectorSorted.push_back(itVP->second);
	// }
		
	clock_t	end		= clock();
	_vLaps	= static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

void	PmergeMe::sortDeque()
{
	clock_t	start	=	clock();
	// std::sort(_dequeInt.begin(), _dequeInt.end());

	_dPairs.clear();
	for (std::deque<int>::const_iterator itD = _dequeInt.begin(); itD + 1 != _dequeInt.end(); itD += 2)
	{
		if (*itD < *(itD + 1))
			_dPairs.push_back(std::make_pair(*itD, *(itD + 1)));
		else
			_dPairs.push_back(std::make_pair(*(itD + 1), *itD));
	}

	for (std::deque<std::pair<int, int> >::iterator itDP = _dPairs.begin(); (itDP + 1) != _dPairs.end(); itDP++)
		if (itDP->second > (itDP + 1)->second)
			std::swap(*itDP, *(itDP + 1));
	
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
	// std::cout << "<-- Vector -->" << std::endl;
	// for (std::vector<int>::const_iterator itV = _vectorInt.begin(); itV != _vectorInt.end(); itV++)
	// 	std::cout << *itV << std::endl;

	// std::cout << "\n<-- Deque -->" << std::endl;
	// for (std::deque<int>::const_iterator itD = _dequeInt.begin(); itD != _dequeInt.end(); itD++)
	// 	std::cout << *itD << std::endl;

	std::cout << "<-- Vector Sorted -->" << std::endl;
	for (std::vector<int>::const_iterator itVSorted = _vectorSorted.begin(); itVSorted != _vectorSorted.end(); itVSorted++)
		std::cout << *itVSorted << std::endl;
}

void	PmergeMe::printPairs() const
{
	std::cout << "<-- Vector Pairs -->" << std::endl;
	for (std::vector<std::pair<int, int> >::const_iterator itVP = _vPairs.begin(); itVP != _vPairs.end(); itVP++)
		std::cout << itVP->first << " | " << itVP->second << std::endl;
	if (_nbInts % 2 != 0)
		std::cout << _oddValue << std::endl;

	std::cout << "<-- Deque Pairs -->" << std::endl;
	for (std::deque<std::pair<int, int> >::const_iterator itDP = _dPairs.begin(); itDP != _dPairs.end(); itDP++)
		std::cout << itDP->first << " | " << itDP->second << std::endl;
	if (_nbInts % 2 != 0)
		std::cout << _oddValue << std::endl;
}
