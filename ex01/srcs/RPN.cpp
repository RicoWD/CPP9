/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:23:28 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/10 02:35:20 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

// RPN::RPN(const std::string op): _op(op)
// {
// 	if (RPN::parse(_op) == false)
// 	{
// 		std::cerr << "Error: Wrong input" << std::endl;
// 		return ;
// 	}
// }

// RPN::RPN(const RPN& cpy): _lst(cpy._lst), _op(cpy._op) {}

// RPN::RPN(const RPN& cpy)
// {
// 	if (this != &cpy)
// 	{
// 		*this->_lst	= cpy._lst;
// 		*this->_op	= cpy._op;
// 	}
		
// 	return (*this);
// }

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
		if (std::isdigit(token[0]))
			lst.push_back(std::stoi(token));
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
		std::cerr << "Error: Invalid expression" << std::endl;
		return ;
	}
	std::cout << lst.back() << std::endl;
}
