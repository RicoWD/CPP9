/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:36:33 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/20 13:34:55 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <sstream>
#include <cctype>

int	main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        return (1);
    }
	
    RPN::calc(av[1]);
    
	return (0);
}
