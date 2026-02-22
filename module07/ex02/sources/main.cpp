/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:49:12 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/22 09:43:44 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>
#include <iostream>

template <typename T>
void	printArray(T & tabl)
{
	for (unsigned int i = 0; i < tabl.size(); i++) {
		std::cout << tabl[i];
		if (i + 1 < tabl.size())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int	main(void)
{
	{
		std::cout << SUC;
		Array<int>	tabl(10);
		try {
			std::cout << "\n========== Created int Array ==========\n";
			for (unsigned int i = 0; i < tabl.size(); i++)
				tabl[i] = i;
			printArray(tabl);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << RST;
	}
	{
		std::cout << INF;
		Array<std::string>	tabl(26);
		try {
			std::cout << "\n======== Created string Array =========\n";
			for (unsigned int i = 0; i < tabl.size(); i++)
				tabl[i] = 'a' + i;
			printArray(tabl);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << RST;
	}
	{
		std::cout << SUC;
		Array<int>	tabl(10);
		try {
			std::cout << "\n========== Created int Array index out ==========\n";
			for (unsigned int i = 0; i < 11; i++)
				tabl[i] = i * 10;
			printArray(tabl);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << RST;
	}
	{
		std::cout << INF;
		Array<float>	tabl(2);
		Array<float>	asignamentTabl(2);
		try {
			tabl[0] = 20.5f;
			tabl[1] = 100.3f;

			std::cout << "\n========== Created Asignament Array ==========\n";
			asignamentTabl = tabl;
			printArray(asignamentTabl);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << RST;
	}
	{
		std::cout << SUC;
		Array<int>	tabl(2);
		try {
			tabl[0] = 0;
			tabl[1] = 1000;

			std::cout << "\n========== Created Copy Array ==========\n";
			Array<int>	copyTabl(tabl);
			printArray(copyTabl);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << RST;
	}
	return (0);
}
