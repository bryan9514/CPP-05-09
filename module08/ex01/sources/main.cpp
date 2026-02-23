/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:47:12 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/23 15:44:34 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main(void)
{
	try {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	//sp.addNumber(100000);
	for (size_t i = 0; i < sp.getVec().size(); i++)
		std::cout << sp.getVec()[i] << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
//	std::cout << sp.shortestSpan() << std::endl;
	return (0);
}
