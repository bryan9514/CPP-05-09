/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:18:07 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/11 16:55:19 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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
		Intern someRandomIntern;
		AForm* rrf = NULL;
		try
		{
			rrf = someRandomIntern.makeForm("shrubbery creation", "target_name");
			Bureaucrat	bureaucrat("Bureaucrat_shrubbey", 137);

			bureaucrat.signAForm(*rrf);
			bureaucrat.executeForm(*rrf);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		delete rrf;
	std::cout << RST;
	}
	std::cout << WRN << "\n============ RobotomyRequestForm ============\n" << std::endl;
	{
		Intern	someRandomIntern;
		AForm*	rrf = NULL;
		try
		{
			rrf = someRandomIntern.makeForm("robotomy request", "target_name");
			Bureaucrat	bureaucrat("Bureaucrat_robotomy", 45);

			bureaucrat.signAForm(*rrf);
			bureaucrat.executeForm(*rrf);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		delete rrf;
	std::cout << RST;
	}
	std::cout << INF << "\n============ PresidentialPardonForm ============\n" << std::endl;
	{
		Intern	someRandomIntern;
		AForm*	rrf = NULL;
		try
		{
			rrf = someRandomIntern.makeForm("presidential pardon", "target_name");
			Bureaucrat	bureaucrat("Bureaucrat_presidential", 5);

			bureaucrat.signAForm(*rrf);
			bureaucrat.executeForm(*rrf);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		delete rrf;
	std::cout << RST;
	}
	return (0);
}
