/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:32:49 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/11 16:00:01 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

/* =========================== default constructor ========================= */
Form::Form(void) :
	_name("default"),
	_signed(false),
	_gradeSigned(150),
	_gradeExecute(150)
{}

/* =========================== name constructor ============================= */
Form::Form(const std::string & name, int gradeSigned, int gradeExecute) :
	_name(name),
	_signed(false),
	_gradeSigned(gradeSigned),
	_gradeExecute(gradeExecute)
{
	if (_gradeSigned < 1 || _gradeExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeSigned > 150 || _gradeExecute > 150)
		throw Form::GradeTooLowException();
}

/* =========================== copy constructor ============================= */
Form::Form(const Form & copy) :
	_name(copy._name),
	_signed(copy._signed),
	_gradeSigned(copy._gradeSigned),
	_gradeExecute(copy._gradeExecute)
{}

/* ======================== copy assignment operator ======================== */
Form & Form::operator=(const Form & other)
{
	if (this != &other) {
		_signed = other._signed;
	}
	return (*this);
}

/* ================================ destructor ============================== */
Form::~Form(void)
{}

/* ================================= gettins ================================ */
const std::string	&Form::getName(void) const
{
	return (_name);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

int		Form::getGradeSigned(void) const
{
	return (_gradeSigned);
}

int		Form::getGradeExecute(void) const
{
	return (_gradeExecute);
}

/* ============================ public methods ============================== */
void	Form::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSigned)
		throw Form::GradeTooLowException();
	_signed = true;
}

/* ============================== exceptions ================================ */
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/* ============================ operator (<<) ================================ */
std::ostream	&operator<<(std::ostream & str, const Form & form)
{
	str << "\nForm " << form.getName()
		<< "\nsigned: " << (form.getSigned() ? "yes" : "no")
		<< "\ngrade to sign: " << form.getGradeSigned()
		<< "\ngrade to execute: " << form.getGradeExecute();
	return (str);
}
