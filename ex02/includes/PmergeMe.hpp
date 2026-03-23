/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 02:45:58 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/23 05:06:29 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iomanip>
# include <iostream>
# include <string>
# include <vector>
# include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_vectorInt;
		std::deque<int>		_dequeInt;

	public:
		// OCF 
		PmergeMe();
		PmergeMe(const PmergeMe& cpy);
		PmergeMe& operator=(const PmergeMe& cpy);
		~PmergeMe();

		// Member Functions
		void	inputToContainer(int ac, char **av);
		void	printNumbers() const;
		void	printContainer() const;
	};

bool	areValidInputs(int ac, char **av);
