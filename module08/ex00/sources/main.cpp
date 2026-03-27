/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:47:12 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/26 16:20:26 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>

int	main(void)
{
	{
		std::cout << SUC;
		std::vector<int> arr;
		try {
			std::cout << "================== (Container type Vector) ============================\n\n";
			arr.push_back(0);
			arr.push_back(2);
			arr.push_back(3);
			arr.push_back(4);
			arr.push_back(5);
			std::cout << "Occurrence find in index: " << std::distance(arr.begin(),::easyfind(arr, 4)) << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << RST;
	}
	{
		
		std::cout << INF << std::endl;
		std::list<int> list;
		try {
			list.push_back(10);
			list.push_back(20);
			list.push_back(30);
			list.push_back(40);
			list.push_back(50);
			std::cout << "=================== (Container type List) =============================\n\n";
			std::cout << "Occurrence find in: " << std::distance(list.begin(),::easyfind(list, 20)) << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << RST;
	}
	{
		std::cout << ERR << std::endl;
		std::list<int> liss;
		try {
			liss.push_back(10);
			liss.push_back(20);
			liss.push_back(30);
			liss.push_back(40);
			liss.push_back(50);
			std::cout << "============= (Container type List) and invalid value ==================\n\n";
			std::list<int>::iterator	tmp = ::easyfind(liss, 2000);
			std::cout << "Occurrence find in: " << std::distance(liss.begin(),tmp) << std::endl;
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << RST;
	}
		return (0);
}
