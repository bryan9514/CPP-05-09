/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:26:26 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/21 21:46:39 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <stdlib.h>

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

void	BitcoinExchange::printfError(typeError error, const std::string data)
{
	std::string	msg;

	if (error == NOT_OPEN)
		msg = "Error: could not open file.";
	if (error == BAD_INPUT)
		msg = "Error: bad input => " + data;
	if (error == TOO_LARGE)
		msg = "Error: too large a number.";
	if (error == NOT_POSITIVE)
		msg = "Error: not a positive number.";
	throw std::runtime_error(msg);
}

void	BitcoinExchange::tokenCsvLine(const std::string & line, std::string & date, std::string & valor)
{
	size_t pos = line.find(',');

	if (line.empty() || pos == std::string::npos)
		printfError(BAD_INPUT, line);
	date = line.substr(0, pos);
	valor = line.substr(pos + 1);
}

void	BitcoinExchange::tokenInputLine(const std::string & line, std::string & date, std::string & valor)
{
	size_t pos = line.find(" | ");

	if (line.empty() || pos == std::string::npos)
		printfError(BAD_INPUT, line);
	date = line.substr(0, pos);
	valor = line.substr(pos + 3);
}

bool	BitcoinExchange::isInteger(const std::string & data)
{
	if (data.empty())
		return (false);
	for (int i = 0; data[i]; i++) {
		if (!std::isdigit(data[i]))
			return (false);
	}
	return (true);
}

void	BitcoinExchange::checkDate(const std::string & date)
{
	std::string	year, month, days;
	int			yearInt, monthInt, daysInt;
	bool		isLeap = false;

	if (date.empty())
		printfError(BAD_INPUT, date);
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		printfError(BAD_INPUT, date);
	year = date.substr(0, 4);
	month = date.substr(5, 2);
	days = date.substr(8, 2);
	if (!isInteger(year) || !isInteger(month) || !isInteger(days))
		printfError(BAD_INPUT, date);
	yearInt = atoi(year.c_str());
	monthInt = atoi(month.c_str());
	daysInt = atoi(days.c_str());
	if ( yearInt < 1 || monthInt < 1 || monthInt > 12 || daysInt < 1)
		printfError(BAD_INPUT, date);
	if (monthInt == 2) {
		if ((yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt % 400 == 0)
			isLeap = true;
		if (isLeap && daysInt > 29)
			printfError(BAD_INPUT, date);
		else if (!isLeap && daysInt > 28)
			printfError(BAD_INPUT, date);
	}
	else if (monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) {
		if (daysInt > 30)
			printfError(BAD_INPUT, date);
	}
	else {
		if (daysInt > 31)
			printfError(BAD_INPUT, date);
	}
}

bool	BitcoinExchange::isFloat(const std::string & data)
{
	int		point = 0;
	size_t	i = 0;

	if (data.empty())
		return false;
	if (data[0] == '.')
		return (false);
	if (data[0] == '+' || data[0] == '-')
		i++;
	if (i == data.size())
		return false;
	while (i < data.size()) {
		if (data[i] == '.')
			point++;
		if ((!std::isdigit(data[i]) &&  data[i] != '.') || point > 1)
			return (false);
		i++;
	}
	return (true);
}

void	BitcoinExchange::checkValor(const std::string & valor)
{
	float	valorFloat;

	if (valor.empty())
		printfError(BAD_INPUT, valor);
	if (!isFloat(valor))
		printfError(BAD_INPUT, valor);
	valorFloat = atof(valor.c_str());
	if (valorFloat < 0)
		printfError(NOT_POSITIVE, valor);
	if (valorFloat > 1000)
		printfError(TOO_LARGE);
}

void	BitcoinExchange::loadFile(const std::string & date, const std::string & valor)
{
	_data[date] = atof(valor.c_str());
}

void	BitcoinExchange::loadData(void)
{
	std::ifstream	dataFile("data.csv");
	std::string		date;
	std::string		valor;
	bool			first = false;

	if (!dataFile)
		throw std::runtime_error("Error: could not open file.");
	std::string	line;
	while (getline(dataFile, line)) {
		if (!first) {
			first = true;
			continue;
		}
		try {
			tokenCsvLine(line, date, valor);
			checkDate(date);
			checkValor(valor);
			loadFile(date, valor);
		} catch (std::exception & e) {

			continue ;
		}
	}
}


void	BitcoinExchange::calculateOperation(const std::string & date, const std::string & valor)
{
	std::map<std::string, float>::iterator	it = _data.lower_bound(date);
	float									value = atof(valor.c_str());
	float									result;

	if (it == _data.end() || it->first != date) {
		if (it == _data.begin())
			printfError(BAD_INPUT, date);
		--it;
	}
	result = value * it->second;
	std::cout << INF << date << RST << " => " << INP << value << RST << " = " << SUC 
		<< result << RST << std::endl;
}

void	BitcoinExchange::processInput(const std::string & nameFileTxt)
{
	std::ifstream	dataFile(nameFileTxt.c_str());
	std::string		date;
	std::string		valor;
	bool			first = false;

	if (!dataFile)
		throw std::runtime_error("Error: could not open file.");
	std::string	line;
	while (getline(dataFile, line)) {
		if (!first) {
			first = true;
			continue;
		}
		try {
			tokenInputLine(line, date, valor);
			checkDate(date);
			checkValor(valor);
			calculateOperation(date, valor);
		} catch (std::exception & e) {
			std::cout << ERR << e.what() << RST << std::endl;
			continue ;
		}
	}
}


