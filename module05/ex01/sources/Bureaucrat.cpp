/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:18:54 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/07 19:03:31 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

/* =========================== default constructor ========================= */
Bureaucrat::Bureaucrat(void) :
	_name("Default"),
	_grade(150)
{}

/* =========================== name constructor ============================= */
Bureaucrat::Bureaucrat(const std::string & name, int grade) :
	_name(name),
	_grade(grade)
{
	if (_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

/* =========================== copy constructor ============================= */
Bureaucrat::Bureaucrat(const Bureaucrat & copy)
{
	*this = copy;
}

/* ======================== copy assignment operator ======================== */
Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

/* ================================ destructor ============================== */
Bureaucrat::~Bureaucrat(void)
{}

/* ============================ public methods ============================== */
const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::increaseGrade(void)
{
	if (_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void	Bureaucrat::signForm(Form & form)
{
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << getName() << " couldn't sing " << form.getName()
			<< " beacause " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream & str, const Bureaucrat & bureaucrat)
{
	str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
		<< "." << std::endl;
	return (str);
}
