/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 02:39:23 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/23 05:29:39 by erpascua         ###   ########.fr       */
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
}
