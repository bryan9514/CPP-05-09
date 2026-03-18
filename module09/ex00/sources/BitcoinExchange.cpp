/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:26:26 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/18 21:52:10 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdio>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <vector>

BitcoinExchange::BitcoinExchange(void) :
	_data()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & copy) :
	_data(copy._data)
{}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange & othre)
{
	if (this != &othre) {
		_data = othre._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{}

// void	BitcoinExchange::parseLine(std::string & line)
// {
// 	 (!line.empty() && )
// 		return ;
//
//
// }

void	BitcoinExchange::tokenizer(std::string & line)
{
	std::vector<std::string>	token;
	size_t						start = 0;

	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] == ',') {
			if (i > start) {
				token.push_back(line.substr(start, i - start));
				start = i + 1;
			}
		}
	}
	token.push_back(line.substr(start));
	for (size_t j = 0; j < token.size(); j++) {
        std::cout << token[j] << std::endl;
	}
}

void	BitcoinExchange::loadData(void)
{
	std::ifstream	dataFile("data.csv");

	if (!dataFile)
		throw std::runtime_error("Error: could not open file.");
	std::string	line;
	while (getline(dataFile, line)) {
		tokenizer(line);
	}
}

//
// void	BitcoinExchange::processInput(const std::string & name)
// {
// 	std::ifstream	fs;
//
// 	fs.open("Data.cvs");
// 	if (!fs)
// 		throw std::runtime_error("Error: could not open file.");
//
//
// }


