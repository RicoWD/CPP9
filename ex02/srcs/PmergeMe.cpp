/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 02:42:18 by erpascua          #+#    #+#             */
/*   Updated: 2026/04/15 13:20:28 by erpascua         ###   ########.fr       */
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
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

/* ************************************************************************** */
// 																			  //
// 						   			GETTERS									  //
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


/* ************************************************************************** */
// 						   			MERGE SORT								  //
/* ************************************************************************** */

void			PmergeMe::merge(std::vector<std::pair<int, int> >& vPairs, int begin, int mid, int end)
{
	int	firstMid	= mid - begin + 1;
	int	lastMid		= end - mid;

	std::vector<std::pair<int, int> >	vFirstMid(firstMid);
	std::vector<std::pair<int, int> >	vLastMid(lastMid);

	for (int i = 0; i < firstMid; i++)
		vFirstMid[i]	= vPairs[begin + i];
	for (int j = 0; j < lastMid; j++)
		vLastMid[j]		= vPairs[mid + 1 + j];
	
	int	i	= 0;
	int	j	= 0;
	int	k	= begin;

	while (i < firstMid && j < lastMid)
	{
		if (vFirstMid[i].second <= vLastMid[j].second)
		{
			vPairs[k] = vFirstMid[i];
			i++;
		}
		else
		{
			vPairs[k] = vLastMid[j];
			j++;
		}
		k++;
	}
	
	while (i < firstMid)
	{
		vPairs[k] = vFirstMid[i];
		i++;
		k++;
	}

	while (j < lastMid)
	{
		vPairs[k] = vLastMid[j];
		j++;
		k++;
	}
}

void			PmergeMe::merge(std::deque<std::pair<int, int> >& dPairs, int begin, int mid, int end)
{
	int	firstMid	= mid - begin + 1;
	int	lastMid		= end - mid;

	std::deque<std::pair<int, int> >	dFirstMid(firstMid);
	std::deque<std::pair<int, int> >	dLastMid(lastMid);

	for (int i = 0; i < firstMid; i++)
		dFirstMid[i]	= dPairs[begin + i];
	for (int j = 0; j < lastMid; j++)
		dLastMid[j]		= dPairs[mid + 1 + j];
	
	int	i	= 0;
	int	j	= 0;
	int	k	= begin;

	while (i < firstMid && j < lastMid)
	{
		if (dFirstMid[i].second <= dLastMid[j].second)
		{
			dPairs[k] = dFirstMid[i];
			i++;
		}
		else
		{
			dPairs[k] = dLastMid[j];
			j++;
		}
		k++;
	}
	
	while (i < firstMid)
	{
		dPairs[k] = dFirstMid[i];
		i++;
		k++;
	}

	while (j < lastMid)
	{
		dPairs[k] = dLastMid[j];
		j++;
		k++;
	}
}


void	PmergeMe::mergeSort(std::vector<std::pair<int, int> >& vPairs, int begin, int end)
{
	if (begin >= end)
		return ;

	int mid = begin + (end - begin) / 2;
	mergeSort(vPairs, begin, mid);
	mergeSort(vPairs, mid + 1, end);
	merge(vPairs, begin, mid, end);
}

void	PmergeMe::mergeSort(std::deque<std::pair<int, int> >& dPairs, int begin, int end)
{
	if (begin >= end)
		return ;

	int mid = begin + (end - begin) / 2;
	mergeSort(dPairs, begin, mid);
	mergeSort(dPairs, mid + 1, end);
	merge(dPairs, begin, mid, end);
}

/* ************************************************************************** */
// 						   			JACOBSTHAL								  //
/* ************************************************************************** */

std::vector<size_t>	PmergeMe::generateJacobsthalOrder(size_t nbPairs)
{
	std::vector<size_t>	order;
	
	if (nbPairs <= 1)
		return order;

	size_t	previous = 1;
	size_t	prevMin1 = 1;
	size_t	prevMin2 = 0;

	while (true)
	{
		size_t current = prevMin1 + 2 * prevMin2;
		if (current > previous)
		{
			size_t	upper = std::min(current, nbPairs);
			
			for (size_t i = upper; i > previous; i--)
				order.push_back(i - 1);

			if (upper == nbPairs)
				break ;
			previous = upper;
		}
		prevMin2 = prevMin1;
		prevMin1 = current;
	}	
	return (order);
}

/* ************************************************************************** */
// 						   			EXECUTION								  //
/* ************************************************************************** */

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
	std::vector<std::pair<int, int> > vPairs;
	
	vPairs.clear();
	for (size_t i = 0; i + 1 < _vector.size(); i += 2)
	{
		if (_vector[i] < _vector[i + 1])
			vPairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
		else
			vPairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
	}

	if (!vPairs.empty())
		mergeSort(vPairs, 0, vPairs.size() - 1);
	
	_vector.clear();
	if (!vPairs.empty())
	{
		_vector.push_back(vPairs[0].first);
		for (std::vector<std::pair<int, int> >::iterator itVP = vPairs.begin(); itVP != vPairs.end(); itVP++)
			_vector.push_back(itVP->second);
		
		std::vector<size_t>	order = generateJacobsthalOrder(vPairs.size());
		for (size_t i = 0; i < order.size(); i++)
		{
			size_t	idx = order[i];
			std::vector<int>::iterator bound = std::lower_bound(_vector.begin(), _vector.end(), vPairs[idx].second);
			if (bound != _vector.end() && *bound == vPairs[idx].second)
				++bound;
			std::vector<int>::iterator pos = std::lower_bound(_vector.begin(), bound, vPairs[idx].first);
			_vector.insert(pos, vPairs[idx].first);
		}
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
	std::deque<std::pair<int, int> > dPairs;

	dPairs.clear();
	for (size_t i = 0; i + 1 < _deque.size(); i += 2)
	{
		if (_deque[i] < _deque[i + 1])
			dPairs.push_back(std::make_pair(_deque[i], _deque[i + 1]));
		else
			dPairs.push_back(std::make_pair(_deque[i + 1], _deque[i]));
	}
	if (!dPairs.empty())
		mergeSort(dPairs, 0, dPairs.size() - 1);

		
	_deque.clear();
	if (!dPairs.empty())
	{
		_deque.push_back(dPairs[0].first);
		for (std::deque<std::pair<int, int> >::iterator itDP = dPairs.begin(); itDP != dPairs.end(); itDP++)
			_deque.push_back(itDP->second);
		
		std::vector<size_t>	order = generateJacobsthalOrder(dPairs.size());
		for (size_t i = 0; i < order.size(); i++)
		{
			size_t	idx = order[i];
			std::deque<int>::iterator bound = std::lower_bound(_deque.begin(), _deque.end(), dPairs[idx].second);
			if (bound != _deque.end() && *bound == dPairs[idx].second)
				++bound;
			std::deque<int>::iterator pos = std::lower_bound(_deque.begin(), bound, dPairs[idx].first);
			_deque.insert(pos, dPairs[idx].first);
		}
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
	// std::cout << "<-- Vector Pairs -->" << std::endl;
	// for (std::vector<std::pair<int, int> >::const_iterator itVP = vPairs.begin(); itVP != vPairs.end(); itVP++)
	// 	std::cout << itVP->first << " | " << itVP->second << std::endl;
	// if (_nbInts % 2 != 0)
	// 	std::cout << _oddValue << std::endl;

	// std::cout << "\n<-- Deque Pairs -->" << std::endl;
	// for (std::deque<std::pair<int, int> >::const_iterator itDP = _dPairs.begin(); itDP != _dPairs.end(); itDP++)
	// 	std::cout << itDP->first << " | " << itDP->second << std::endl;
	if (_nbInts % 2 != 0)
		std::cout << _oddValue << std::endl;
}
