/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:18:54 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/11 15:47:07 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <ostream>

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

/* ================================= getters ================================ */
const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (_grade);
}

/* ============================ public methods ============================== */
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

void	Bureaucrat::signAForm(AForm & form)
{
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << getName() << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm & form) const
{
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;;
	} catch (std::exception & e) {
		std::cout << getName() << " couldn't execute "
			<< form.getName() << " because " << e.what() << std::endl;;
	}
}

/* ============================== exceptions ==================================== */
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

/* ============================ operator (<<) ===================================== */
std::ostream	&operator<<(std::ostream & str, const Bureaucrat & bureaucrat)
{
	str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
		<< ".";
	return (str);
}
