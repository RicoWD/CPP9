/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:23:28 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/20 13:34:24 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

void	RPN::calc(std::string op)
{
	std::list<int>		lst;
	std::istringstream	iss(op);
	std::string			token;

	while (iss >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			lst.push_back(std::atoi(token.c_str()));
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (lst.size() < 2)
			{
				std::cerr << "Error: Not enough operands" << std::endl;
				return ;
			}
			int b = lst.back();
			lst.pop_back();
			int a = lst.back();
			lst.pop_back();

			if (token == "+")
				lst.push_back(a + b);
			else if (token == "-")
				lst.push_back(a - b);
			else if (token == "*")
				lst.push_back(a * b);
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error: Division by zero not allowed" << std::endl;
					return ;
				}
				lst.push_back(a / b);
			}
		}
		else
		{
			std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
			return ;
		}
	}
	if (lst.size() != 1)
	{
		if (op.find("+-*/") != std::string::npos)
			std::cout << op << std::endl;
		else
			std::cerr << "Error: Invalid expression" << std::endl;
		return ;
	}
	std::cout << lst.back() << std::endl;
}


/* ************************************************************************** */
// 																			  //
// 						   			EXCEPTION								  //
//																	 		  //
/* ************************************************************************** */

class RPN::NotEnoughOperandException::what() const throw()
{
	return ("Not Enough Operand Exception");
}

class RPN::DivisionByZeroException::what() const throw()
{
	return ("Division By Zero Exception");
}

class RPN::InvalideTokenException::what() const throw()
{
	return ("Invalide Token Exception");
}

class RPN::InvalideTokenException::what() const throw()
{
	return ("Invalide Token Exception");
}