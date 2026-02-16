/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:15:10 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/16 16:01:58 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include <iostream>

int	main(void)
{
	Data	data;
	Data	*ptr;
	Data	*newPtr;
	
	data._id = 1;
	data._name = "Primero";
	
	ptr = &data;
	std::cout << "========== Struct Data ===========" << std::endl;
	std::cout << "Address ptr: " << ptr << std::endl;
	std::cout << "Address data: " << &data << std::endl;
	std::cout << "id: " << data._id << std::endl;
	std::cout << "Name: " << data._name << std::endl;
	
	std::cout << "\n========== Serialize ===========" << std::endl;
	uintptr_t raw = Serialize::serialize(ptr);
	std::cout << "Raw value: " << raw << std::endl;
	
	std::cout << "\n========== Deserialize ===========" << std::endl;
	newPtr = Serialize::deserialize(raw);
	std::cout << "Address: " << newPtr << std::endl;
	std::cout << "id: " << newPtr->_id << std::endl;
	std::cout << "name: " << newPtr->_name << std::endl;
	
	std::cout << "\n========== Comparison ==========" << std::endl;
	if (ptr == newPtr)
		std::cout << "Pointers are equal!" << std::endl;
	else
		std::cout << "Pointers are NOT equal!" << std::endl;
	return 0;
}
