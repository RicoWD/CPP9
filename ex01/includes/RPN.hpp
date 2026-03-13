/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:12:26 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/13 13:35:04 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <exception>

class RPN
{
	private:
		RPN();
		~RPN();
		RPN(const RPN& cpy);
		RPN& operator=(const RPN& cpy);

	public:
		static	void	calc(std::string op);

	class NotEnoughOperandException: public std::exception { public: const char *what() const throw(); };
	class DivisionByZeroException: public std::exception { public: const char *what() const throw(); };
	class InvalideTokenException: public std::exception { public: const char *what() const throw(); };
	class InvalideExpressionException: public std::exception { public: const char *what() const throw(); };
};
