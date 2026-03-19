/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:26:26 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/19 12:34:07 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdio>
#include <stdexcept>
#include <fstream>
#include <iostream>

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

void	printfError()

void	BitcoinExchange::tokenizer(std::string & line, std::string & date, std::string & valor)
{
	size_t		start = 0;

	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] == ',') {
			if (i > start) {
				date = line.substr(start, i - start);
				start = i + 1;
			}
		}
	}
	valor = line.substr(start);
	for (size_t j = 0; j < 2; j++) {
        std::cout << date << std::endl;
        std::cout << valor << std::endl;
	}
}

bool	checkDate(std::string)
{
	for (int i = 0; date[i] ; i++) {
		if (!std::isdigit(date[i])) {
			std::cout << "Error: bad input => 2001-42-42";
			return (false);
		}
	}
	return (true);
}

void	BitcoinExchange::loadData(void)
{
	std::ifstream	dataFile("data.csv");
	std::string		date;
	std::string		valor;

	if (!dataFile)
		throw std::runtime_error("Error: could not open file.");
	std::string	line;
	while (getline(dataFile, line)) {
		tokenizer(line, date, valor);
		if (!checkDate(date)) {
			continue ;
		if (!checkValor(valor)) {
			std::cout << ""
		}
		//checkValor(valor);
		i++;
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


