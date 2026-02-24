/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:47:12 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/24 13:22:53 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>
#include <list>

template <typename T>
void	printArray(T & tabl)
{
	for (unsigned int i = 0; i < tabl.size(); i++) {
		std::cout << tabl[i];
		if (i < tabl.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int	main(void)
{
	std::list<int>	l;
	l.push_back(10);
	l.push_back(1);
	l.push_back(5);
	l.push_back(90);
	l.push_back(50);
	l.push_back(12);

	{
		std::cout << "============================ Test subject ============================\n\n";		
		try {
			Span sp = Span(5);
			
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			printArray(sp.getVec());
			std::cout << INF << sp.shortestSpan() << RST << std::endl;
			std::cout << SUC << sp.longestSpan() << RST << std::endl;
		} catch (std::exception & e){
			std::cout << ERR << e.what() << SUC << std::endl;
		}
	}
	{
		std::cout << "\n============================ insertRange ============================\n\n";		
		try {
			Span	sp = Span(6);

			sp.insertRange(l.begin(), l.end());
			printArray(sp.getVec());
			std::cout << INF << sp.shortestSpan() << RST << std::endl;
			std::cout << SUC << sp.longestSpan() << RST << std::endl;
		} catch (std::exception & e) {
			std::cout << ERR << e.what() << SUC << std::endl;
		}
	}
	{
		std::cout << RST << "\n============================ Full vector ============================\n\n";		
		try {
			Span	sp = Span(2);

			sp.insertRange(l.begin(), l.end());
			std::cout << INF << sp.shortestSpan() << RST << std::endl;
			std::cout << SUC << sp.longestSpan() << RST << std::endl;
			printArray(sp.getVec());
		} catch (std::exception & e) {
			std::cout << ERR << e.what() << SUC << std::endl;
		}
	}
	{
		std::cout << RST << "\n============================ Only one value ============================\n\n";		
		try {
			Span	sp = Span(1);
			
			sp.addNumber(2);
			std::cout << INF << sp.shortestSpan() << RST << std::endl;
			std::cout << SUC << sp.longestSpan() << RST << std::endl;
			printArray(sp.getVec());
		} catch (std::exception & e) {
			std::cout << ERR << e.what() << SUC << std::endl;
		}
	}
	return (0);
}
