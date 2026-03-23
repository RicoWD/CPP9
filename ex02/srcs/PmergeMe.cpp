/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 02:42:18 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/23 05:29:24 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ************************************************************************** */
// 																			  //
// 						   	  Orthodox Canonical Form						  //
//																	 		  //
/* ************************************************************************** */

PmergeMe::PmergeMe() {}

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
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

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
	}
}

void	PmergeMe::printContainer() const
{
	std::cout << "<-- Vector -->" << std::endl;
	for (std::vector<int>::const_iterator itV = _vectorInt.begin(); itV != _vectorInt.end(); itV++)
		std::cout << *itV << std::endl;

	std::cout << "\n<-- Deque -->" << std::endl;
	for (std::deque<int>::const_iterator itD = _dequeInt.begin(); itD != _dequeInt.end(); itD++)
		std::cout << *itD << std::endl;
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

		for (size_t j = 0; j < std::strlen(av[i]); j++)
		{
			if (!std::isdigit(static_cast<unsigned char>(av[i][j])))
				return (std::cerr << "Error: " << av[i] << " is not a valid input" << std::endl, false);
		}

		long tmp = std::atol(av[i]);
		if (tmp <= 0 || tmp > INT_MAX)
			return (std::cerr << "Error: " << av[i] << " is not a valid number" << std::endl, false);
	}
	return (true);
}
