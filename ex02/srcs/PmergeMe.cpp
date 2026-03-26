/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 02:42:18 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/26 04:42:15 by erpascua         ###   ########.fr       */
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

void			merge(std::vector<std::pair<int, int> >& vPairs, int begin, int mid, int end)
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
		if (vFirstMid[i] <= vLastMid[j])
		{
			vPairs[k] = vFirstMid[i];
			i++;
		}
		else
		{
			vPairs[k] = vLastMid[i];
		}
		k++;
	}
	
	while (i < firstMid)
	{
		vPairs[k] = vLastMid[i];
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
		vPairs[k] = vLastMid[i];
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
		dPairs[k] = dLastMid[i];
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


void	PmergeMe::sortVector()
{
	clock_t	start	=	clock();
	std::vector<std::pair<int, int> > vPairs;
	
	vPairs.clear();
	for (std::vector<int>::const_iterator itV = _vector.begin(); itV < _vector.end() - 1; itV += 2)
	{
		if (*itV < *(itV + 1))
			vPairs.push_back(std::make_pair(*itV, *(itV + 1)));
		else
			vPairs.push_back(std::make_pair(*(itV + 1), *itV));
	}

	mergeSort(vPairs, 0, vPairs.size() - 1);
	
	_vector.clear();
	_vector.push_back(vPairs.begin()->first);
	for (std::vector<std::pair<int, int> >::iterator itVP = vPairs.begin(); itVP != vPairs.end(); itVP++)
		_vector.push_back(itVP->second);
	// for (std::vector<std::pair<int, int> >::iterator itVP = vPairs.begin(); itVP != vPairs.end(); itVP++)
	// {
	// 	std::vector<int>::iterator pos = std::lower_bound(_vector.begin(), _vector.end(), itVP->first);
	// 	_vector.insert(pos, itVP->first);
	// }
	// std::vector<size_t> buildJacorbsthalOrder(size_t pairCount);
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
	for (std::deque<int>::const_iterator itD = _deque.begin(); itD < _deque.end() - 1; itD += 2)
	{
		if (*itD < *(itD + 1))
			dPairs.push_back(std::make_pair(*itD, *(itD + 1)));
		else
			dPairs.push_back(std::make_pair(*(itD + 1), *itD));
	}

	// for (size_t i = 0; i < dPairs.size(); i++)
	// {
	// 	for (size_t j = 0; j + 1 < dPairs.size() - i; j++)
	// 	{
	// 		if (dPairs[j].second > dPairs[j + 1].second)
	// 			std::swap(dPairs[j], dPairs[j + 1]);
	// 	}
	// }

	mergeSort(dPairs, 0, dPairs.size() - 1);

		
	_deque.clear();
	for (std::deque<std::pair<int, int> >::iterator itDP = dPairs.begin(); itDP != dPairs.end(); itDP++)
		_deque.push_back(itDP->second);
	for (std::deque<std::pair<int, int> >::iterator itDP = dPairs.begin(); itDP != dPairs.end(); itDP++)
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
