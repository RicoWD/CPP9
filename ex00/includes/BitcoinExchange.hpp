/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:37:24 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/20 03:52:46 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

	public:
		// OCF
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& cpy);
		BitcoinExchange& operator=(const BitcoinExchange& cpy);
		~BitcoinExchange();

		// Getters
		const std::map<std::string, float>&	getData() const;

		// Member Functions
		void	loadDatabase(const std::string& filename);
		void	processInput(const std::string& filename);

		bool	isValidDate(const std::string& date) const;
		bool	isValidValue(const float value) const;
		float	getRateForDate(const std::string& date) const;
};
