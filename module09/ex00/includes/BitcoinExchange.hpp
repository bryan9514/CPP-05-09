/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:23:57 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/21 21:35:56 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

# define RST "\033[0m"
# define ERR "\033[0;91m"
# define WRN "\033[0;93m"
# define SUC "\033[0;92m"
# define INF "\033[0;96m"
# define INP "\033[0;94m"

enum typeError
{
	NOT_OPEN,
	NOT_POSITIVE,
	BAD_INPUT,
	TOO_LARGE
};

class BitcoinExchange
{
private:
	std::map<std::string, float>	_data;

	void 	printfError(typeError error, const std::string data = "");
	void	tokenCsvLine(const std::string & line, std::string & date, std::string & valor);
	void	tokenInputLine(const std::string & line, std::string & date, std::string & valor);
	bool	isInteger(const std::string & data);
	void	checkDate(const std::string & date);
	bool	isFloat(const std::string & data);
	void	checkValor(const std::string & valor);
	void	loadFile(const std::string & date, const std::string & valor);
	void	calculateOperation(const std::string & date, const std::string & valor);

public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange & copy);
	BitcoinExchange & operator=(const BitcoinExchange & other);
	~BitcoinExchange(void);

	void	loadData(void);
	void	processInput(const std::string & nameFileTxt);
};


#endif
