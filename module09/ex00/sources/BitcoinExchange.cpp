/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:26:26 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/18 12:33:18 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
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

void	BitcoinExchange::openFile(const std::string & name)
{
	std::ifstream	fs;

	if (!myReadFile)
		throw std::runtime_error("Error: could not open file.");


}


