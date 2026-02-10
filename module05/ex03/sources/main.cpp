/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:18:07 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/10 15:34:25 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));
	std::cout << SUC << "============ ShrubberyCreationForm ============\n" << std::endl;
	{
		AForm*	shrubbery = NULL;
		try
		{
			shrubbery = new ShrubberyCreationForm("tercer-nivel");
			Bureaucrat	tercer("tercer-nivel", 137);

			tercer.signAForm(*shrubbery);
			tercer.executeForm(*shrubbery);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		delete shrubbery;
	std::cout << RST;
	}
	std::cout << WRN << "\n============ RobotomyRequestForm ============\n" << std::endl;
	{
		AForm*	roboto = NULL;
		try
		{
			roboto = new RobotomyRequestForm("target_name");
			Bureaucrat	bureaucrat("Bureaucrat_name", 45);

			bureaucrat.signAForm(*roboto);
			bureaucrat.executeForm(*roboto);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		delete roboto;
	std::cout << RST;
	}
	std::cout << RST << "\n============ PresidentialPardonForm ============\n" << std::endl;
	{
		AForm*	presidential = NULL;
		try
		{
			presidential = new PresidentialPardonForm("primer-nivel");
			Bureaucrat	primer("primer", 5);

			primer.signAForm(*presidential);
			primer.executeForm(*presidential);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		delete presidential;
	std::cout << RST;
	}
	return (0);
}
