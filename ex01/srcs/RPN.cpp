/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:23:28 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/09 19:54:33 by erpascua         ###   ########.fr       */
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
	(void)op;
	// std::stringstream(op);
}
