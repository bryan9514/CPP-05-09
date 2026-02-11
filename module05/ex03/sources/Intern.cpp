/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:21:17 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/11 13:12:17 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/* =========================== default constructor ========================== */
Intern::Intern(void)
{}

/* =========================== copy constructor ============================= */
Intern::Intern(const Intern & copy)
{
	(void)copy;
}

/* ======================== copy assignment operator ======================== */
Intern & Intern::operator=(const Intern & other)
{
	(void)other;
	return (*this);
}

/* ================================ destructor ============================== */
Intern::~Intern(void)
{}

/* ============================ public methods ============================== */
AForm*	Intern::createShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string nameForm, std::string target)
{
	const std::string	formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm*	(Intern::*ptrFuntions[3])(std::string) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm 
	};

	for (int i = 0; i < 3; i++) {
		if (nameForm == formNames[i]) {
			std::cout << "Intern creates " << nameForm << std::endl;
			return ((this->*ptrFuntions[i])(target));
		}
	}
	throw Intern::FormNotFoundException();
}

/* ============================== exceptions ================================ */
const char	*Intern::FormNotFoundException::what() const throw()
{
	return ("Intern cannot create form");
}
