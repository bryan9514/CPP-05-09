/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:28:16 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/25 16:58:38 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << ERR << "Error: could not open file." << RST << std::endl;
		return (1);
	}
	
	BitcoinExchange	btc;
	try {
		btc.loadData();
		btc.processInput(av[1]);
	} catch (const std::exception & e) {
		std::cout << ERR << e.what() << RST << std::endl;
		return (1);
	}
	return(0);
}
