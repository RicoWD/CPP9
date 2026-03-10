/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:12:26 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/10 02:35:40 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <list>
#include <iostream>
#include <iomanip>
#include <sstream>

class RPN
{
	private:
		RPN();
		~RPN();
		RPN(const RPN& cpy);
		RPN& operator=(const RPN& cpy);

	public:
		static	void	calc(std::string op);
};
