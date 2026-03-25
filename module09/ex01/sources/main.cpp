/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:06:21 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/23 13:08:27 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << ERR << "Error" << RST << std::endl;
		return (1);
	}
	try {
		RPN rpn;
		rpn.process(av[1]);
	} catch (std::exception & e) {
		std::cerr << ERR << "Error" << RST << std::endl;
		return (1);
	}
	return (0);
}
