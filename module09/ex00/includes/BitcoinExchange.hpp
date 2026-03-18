/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:23:57 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/18 21:52:10 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_data;

	void	parseLine(std::string & line);
	void	tokenizer(std::string & line);

public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange & copy);
	BitcoinExchange & operator=(const BitcoinExchange & other);
	~BitcoinExchange(void);

	void	loadData(void);
	void	processInput(const std::string & name);

};

#endif
