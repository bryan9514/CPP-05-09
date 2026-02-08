/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:18:07 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/08 10:52:36 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << SUC << "======== Good Form ========\n" << std::endl;
	{
		try
		{
			Form		form("01-Contract", 11, 11);
			Bureaucrat	goodBure("Good", 10);

			std::cout << goodBure << std::endl;
			goodBure.decreaseGrade();
			std::cout << goodBure << std::endl;
			goodBure.increaseGrade();
			std::cout << goodBure << std::endl;
			goodBure.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << RST;
	}
	std::cout << WRN << "\n======== High Form ========\n" << std::endl;
	{
		try
		{
			Form		form("02-Contract", -1, -1);
			Bureaucrat	highBure("High", 1);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << RST;
	}
	std::cout << ERR << "\n======== Low Form ========\n" << std::endl;
	{
		try
		{
			Form		form("03-Contract", 151, 151);
			Bureaucrat	lowBure("Low", 149);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << RST;
	}
	std::cout << ERR << "\n======== Insufficient Grade Bureaucrat ========\n" << std::endl;
	{
		try
		{
			Form		form("03-Contract", 1, 1);
			Bureaucrat	InsuBure("Insufficient", 149);

			InsuBure.signForm(form);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << RST;
	}
	return (0);
}
