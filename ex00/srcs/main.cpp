/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:29:22 by erpascua          #+#    #+#             */
/*   Updated: 2026/04/01 02:20:47 by erpascua         ###   ########.fr       */
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
	
	std::string dbFilename = "data.csv";
	std::ifstream dbFile(dbFilename.c_str(), std::ifstream::in);
	if (!dbFile)
	{
		dbFilename = "ex00/data.csv";
		dbFile.clear();
		dbFile.open(dbFilename.c_str(), std::ifstream::in);
	}
	if (!dbFile)
	{
		std::cerr << "Error: cannot open database file: data.csv" << std::endl;
		return (1);
	}
	dbFile.close();

	const std::string inputFilename = argv[1];
	BitcoinExchange data;

	if (!data.loadDatabase(dbFilename))
		return (1);
	data.processInput(inputFilename);
}
