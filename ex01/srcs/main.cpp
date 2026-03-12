/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:36:33 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/12 11:00:24 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <sstream>
#include <cctype>

// bool	isOpSymbol(char c)
// {
//     return (c == '*' || c == '/' || c == '+' || c == '-');
// }

// bool	isValid(const std::string &input)
// {
//     std::istringstream	iss(input);
//     std::string			token;
//     int					stackCount = 0;

//     while (iss >> token)
//     {
//         if (token.size() == 1 && std::isdigit(token[0]))
//         {
//             stackCount++;
//         }
//         else if (token.size() == 1 && isOpSymbol(token[0]))
//         {
//             if (stackCount < 2)
//             {
//                 std::cerr << "Error: not enough operands before operator '" << token << "'" << std::endl;
//                 return (false);
//             }
//             stackCount--;
//         }
//         else
//         {
//             std::cerr << "Error: invalid token '" << token << "'" << std::endl;
//             return (false);
//         }
//     }
//     return (stackCount == 1);
// }

int	main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        return (1);
    }

    // if (!isValid(av[1]))
    // {
    //     std::cerr << "Error: Wrong format" << std::endl;
    //     return (1);
    // }
	
    RPN::calc(av[1]);
    
	return (0);
}
