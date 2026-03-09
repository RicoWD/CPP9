/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:36:33 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/09 20:11:02 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

bool	isOpSymbol(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return (true);
	return (false);
}

bool	isValid(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			std::cerr << "Error 0: input[" << i << "] is not a digit: |" << input[i] << "|" << std::endl;
			return (false);
		}
		i++;
		if (i % 2 == 0 && !isspace(input[i]))
		{
			std::cerr << "Error 1: input[" << i << "] is not a space: |" << input[i] << "|" << std::endl;
			return (false);
		}
		i++;
		if (i % 4 == 0 && !isdigit(input[i]))
		{
			std::cerr << "Error 2: input[" << i << "] is not a digit: |" << input[i] << "|" << std::endl;
			return (false);
		}
		i++;
		if (i % 4 == 0 && !isOpSymbol(input[i]))
		{
			std::cerr << "Error 2: input[" << i << "] is not a valid op symbol: |" << input[i] << "|" << std::endl;
			return (false);
		}
	}
	// for (size_t i = 0; i < input.length(); i++)
	// {
	// 	if (!isdigit(input[i]))
	// 		return (false);
	// 	if (!isspace(input[i] % 2))
	// 		return (false);
	// 	if (!isdigit(input[i] % 4))
	// 		return (false);
	// 	if (!isOpSymbol(input[i] % 4))
	// 		return (false);
	// }
	return (true);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}

	if (isValid(av[1]) == false)
	{
		std::cerr << "Error: Wrong format" << std::endl;
		return (1);
	}

}
