/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:29:22 by erpascua          #+#    #+#             */
/*   Updated: 2026/03/20 05:21:15 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return (1);
	}
	
	const std::string dbFilename = "data.csv";
	const std::string inputFilename = argv[1];
	BitcoinExchange data;

	data.loadDatabase(dbFilename);
	data.processInput(inputFilename);
	// const std::map<std::string, float>& db = data.getData();

	// for (std::map<std::string, float>::const_iterator it = db.begin(); it != db.end(); it++)
	// 	std::cout << it->first << " || " << it->second << std::endl;
}
