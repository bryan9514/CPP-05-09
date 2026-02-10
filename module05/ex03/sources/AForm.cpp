/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:32:49 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/10 12:37:39 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

/* =========================== default constructor ========================= */
AForm::AForm(void) :
	_name("default"),
	_target("default"),
	_signed(false),
	_gradeSigned(150),
	_gradeExecute(150)
{}

/* =========================== name constructor ============================= */
AForm::AForm(const std::string & name, const std::string & target, int gradeSigned, int gradeExecute) :
	_name(name),
	_target(target),
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
	_target(copy._target),
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

const std::string	&AForm::getTarget(void) const
{
	return (_target);
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

void	AForm::execute(const Bureaucrat & execute) const
{
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (execute.getGrade() > _gradeExecute)
		throw AForm::GradeTooLowException();
	doAction();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("form is not signed");
}

std::ostream	&operator<<(std::ostream & str, const AForm & form)
{
	str << "\nAForm " << form.getName()
		<< "\nsigned: " << (form.getSigned() ? "yes" : "no")
		<< "\ngrade to sign: " << form.getGradeSigned()
		<< "\ngrade to execute: " << form.getGradeExecute();
	return (str);
}
