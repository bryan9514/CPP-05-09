/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:23:57 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/18 12:23:57 by brturcio         ###   ########.fr       */
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

public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange & copy);
	BitcoinExchange & operator=(const BitcoinExchange & other);
	~BitcoinExchange(void);

	void	openFile(const std::string & name);
	void	tokenizer(std::string & line);

};

#endif
