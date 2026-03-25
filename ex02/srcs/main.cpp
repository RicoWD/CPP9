/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 02:39:23 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/25 02:44:57 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (!areValidInputs(ac, av))
		return (1);
	
	PmergeMe sort;

	sort.inputToContainer(ac, av);
	// sort.printContainer();

	std::cout << std::setw(10) << "Before : ";
	sort.printNumbers();
	sort.globalSort();
	std::cout << std::setw(10) << "After : ";
	sort.printNumbers();
	
	std::cout << "Time to process a range of " << sort.getNbInts() << " elements with std::vector : " << sort.getVLaps() << " us" << std::endl;
	std::cout << "Time to process a range of " << sort.getNbInts() << " elements with std::deque : " << sort.getDLaps() << " us" << std::endl;
	
	// sort.printPairs();
	// sort.printContainer();
	return (0);
}
