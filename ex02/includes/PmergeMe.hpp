/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 02:45:58 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/25 02:27:19 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iomanip>
# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <utility>
# include <climits>
# include <cstdlib>
# include <cstring>
# include <cctype>
# include <ctime>
# include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		unsigned int		_nbInts;
		bool				_isOdd;
		int					_oddValue;
		double				_vLaps;
		double				_dLaps;
		
		std::vector<std::pair<int, int> >	_vPairs;
		std::deque<std::pair<int, int> >	_dPairs;


	public:
		// OCF 
		PmergeMe();
		PmergeMe(const PmergeMe& cpy);
		PmergeMe& operator=(const PmergeMe& cpy);
		~PmergeMe();

		// Getters
		unsigned int	getNbInts() const;
		double			getVLaps() const;
		double			getDLaps() const;
		
		// Member Functions
		void			inputToContainer(int ac, char **av);
		void			printContainer() const;
		// Sort Functions
		void			globalSort();
		void			sortVector();
		void			sortDeque();
		
		// Debug
		void			printNumbers() const;
		void			printPairs() const;
	};

bool	areValidInputs(int ac, char **av);
