/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:32:49 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/08 13:10:35 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

/* =========================== default constructor ========================= */
AForm::AForm(void) :
	_name("default"),
	_signed(false),
	_gradeSigned(150),
	_gradeExecute(150)
{}

/* =========================== name constructor ============================= */
AForm::AForm(const std::string & name, int gradeSigned, int gradeExecute) :
	_name(name),
	_signed(false),
	_gradeSigned(gradeSigned),
	_gradeExecute(gradeExecute)
{
	if (_gradeSigned < 1 || _gradeExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeSigned > 150 || _gradeExecute > 150)
		throw AForm::GradeTooLowException();
}

/* =========================== copy constructor ============================= */
AForm::AForm(const AForm & copy) :
	_name(copy._name),
	_signed(copy._signed),
	_gradeSigned(copy._gradeSigned),
	_gradeExecute(copy._gradeExecute)
{}

/* ======================== copy assignment operator ======================== */
AForm & AForm::operator=(const AForm & other)
{
	if (this != &other) {
		_signed = other._signed;
	}
	return (*this);
}

/* ================================ destructor ============================== */
AForm::~AForm(void)
{}

/* ================================= gettins ================================ */
const std::string	&AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

int		AForm::getGradeSigned(void) const
{
	return (_gradeSigned);
}

int		AForm::getGradeExecute(void) const
{
	return (_gradeExecute);
}

/* ============================ public methods ============================== */
void	AForm::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSigned)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream & str, const AForm & form)
{
	str << "\nAForm " << form.getName()
		<< "\nsigned: " << (form.getSigned() ? "yes" : "no")
		<< "\ngrade to sign: " << form.getGradeSigned()
		<< "\ngrade to execute: " << form.getGradeExecute();
	return (str);
}
