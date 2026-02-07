/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:32:39 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/07 14:23:30 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeSigned;
	const int			_gradeExecute;

public:
	Form(void);
	Form(const std::string & name, int gradeSigned, int _gradeExecute);
	Form(const Form & copy);
	Form & operator=(const Form & other);
	~Form(void);

	const std::string	&getName(void) const;
	bool	getSigned(void) const;
	int		getGradeSigned(void) const;
	int		getGradeExecute(void) const;

	void	beSigned(const Bureaucrat & bureaucrat);

class GradeTooHighException : public std::exception
{
public:
	virtual const char * what() const throw();
};

class GradeTooLowException : public std::exception
{
public:
	virtual const char * what() const throw();
};

};

#endif
