/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:28:16 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/18 17:34:36 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	
	BitcoinExchange	btc;
	try {
		btc.loadData();
		//btc.processInput(av[1]);
	} catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return(0);
}
