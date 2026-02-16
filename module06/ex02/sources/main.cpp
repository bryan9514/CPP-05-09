/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:04:36 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/16 16:29:12 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base	*generate(void)
{
	switch (rand() % 3) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			std::cout << "generator has failed" << std::endl;
			return (NULL);
	}
}

void identify(Base* p)
{
	if (!p)
		return ;
	if (dynamic_cast<A *>(p))
		std::cout << "Detected type: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Detected type: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Detected type: C" << std::endl;
}

void identify(Base& p)
{
	try {
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Detected type: A" << std::endl;
		return ;
	} catch (...) {}
	try {
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Detected type: B" << std::endl;
		return ;
	} catch (...) {}
	try {
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Detected type: C" << std::endl;
		return ;
	} catch (...) {}
}

int	main(void)
{
	std::srand(std::time(NULL));
	Base	*ptr = generate();

	std::cout << "================ POINTER IDENTIFICATION ================" <<  std::endl;
	identify(ptr);
	std::cout << std::endl;
	std::cout << "=============== REFERENCE IDENTIFICATION ===============" << std::endl;
	identify(*ptr);
	delete ptr;
	return (0);
}
