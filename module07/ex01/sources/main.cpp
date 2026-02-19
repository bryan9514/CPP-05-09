/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:16:16 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/19 19:40:27 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void	incrementInt(int & n)
{
	n++;
}

void	printInt(const int & n)
{
	std::cout << n << std::endl;
}

void	ChangeString(std::string & string)
{
	string = "Nothing";
}

void	printString(const std::string & string)
{
	std::cout << string << std::endl;
}

int	main(void)
{
	{
		std::cout << SUC;
		int	arr[] = {1, 2, 3};

		std::cout << "============= Original values printInt ================\n";
		iter(arr, 3, printInt);
		std::cout << "============ Increment values incrementInt ============\n\n";
		std::cout << "Increment values.......................................\n\n";
		iter(arr, sizeof(arr)/sizeof(arr[0]), incrementInt);
	
		std::cout << "=============== After increment printInt ==============\n";
	    iter(arr, 3, printInt);
		std::cout << RST;
	}
	{
		std::cout << INF;
		std::string	arr[] = {"hello", "wordl", "something"};
		std::cout << "=========== Original values printString ===============\n";
		iter(arr, 3, printString);

		std::cout << "============ Changing values ChangeString =============\n\n";
		std::cout << "Changing values.......................................\n\n";
		iter(arr, 3, ChangeString);

		std::cout << "============ After increment printString ==============\n";
		iter(arr, 3, printString);
		std::cout << RST;
	}
	return (0);
}
