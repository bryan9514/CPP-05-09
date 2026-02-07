/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:18:07 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/05 19:45:23 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << SUC << "======== Good Bureaucrat  ========\n" << std::endl;
	{
		try
		{
			Bureaucrat	goodBure("Good", 10);

			std::cout << goodBure << std::endl;
			goodBure.decreaseGrade();
			goodBure.decreaseGrade();
			std::cout << goodBure << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << RST;
	}
	std::cout << WRN << "\n======== Low Bureaucrat  ========\n" << std::endl;
	{
		try
		{
			Bureaucrat	lowBure("Low", -100);

			std::cout << "lowBure is: " << lowBure << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << RST;
	}
	std::cout << ERR << "\n======== High Bureaucrat  ========\n" << std::endl;
	{
		try
		{
			Bureaucrat	highBure("High", 256);

			std::cout << "highBure is: " << highBure << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << RST;
	}
	return (0);
}
