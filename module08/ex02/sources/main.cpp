/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:03:28 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/26 16:42:50 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

template <typename T>
void	printStack(const MutantStack<T> & myStack)
{
	typename MutantStack<T>::const_iterator it = myStack.begin();
	typename MutantStack<T>::const_iterator ite = myStack.end();

	std::cout << "====== all stack ======" <<std::endl;
	std::cout << SUC;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << RST;
}

int main()
{
	{
		std::cout << "======================== Example subject  ==========================" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << INF << "top : " << RST;
		int top = mstack.top();
		std::cout << top << std::endl;
		std::cout << ERR << "pop : " << top << std::endl << RST;
		mstack.pop();
		std::cout << INF << "size stack: "<<mstack.size() << RST << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		printStack(mstack);
		std::stack<int> s(mstack);
		std::cout << INF << "top of s: " << RST;
		top = s.top();
		std::cout << top << std::endl;
	}
	{
		std::cout << "======================== stack std::string ==========================" << std::endl;
		MutantStack<std::string> mstack;

		mstack.push("uno");
		mstack.push("dos");
		std::cout << INF << "top : " << RST;
		std::string top = mstack.top();
		std::cout << top << std::endl;
		std::cout << ERR << "pop : " << top << std::endl << RST;
		mstack.pop();
		std::cout << INF << "size stack: "<<mstack.size() << RST << std::endl;
		mstack.push("tres");
		mstack.push("cuatro");
		mstack.push("cinco");
		mstack.push("seis");
		printStack(mstack);
		std::stack<std::string> s(mstack);
		std::cout << INF << "top of s: " << RST;
		top = s.top();
		std::cout << top << std::endl;
	}
	return 0;
}
