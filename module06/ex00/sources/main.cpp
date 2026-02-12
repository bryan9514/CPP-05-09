/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:33:36 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/12 13:52:47 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>

int	main(int ac, char **av)
{
	{
	try {
		if (ac != 2)
			throw  ScalarConverter::BadNumberArguments();
		ScalarConverter::convert(av[1]);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} 
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	}
	return (0);
}
