/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:32:39 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/09 15:07:52 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <exception>
#include <ostream>
#include <string>
class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const std::string	_target;
	bool				_signed;
	const int			_gradeSigned;
	const int			_gradeExecute;

public:
	AForm(void);
	AForm(const std::string & name, int gradeSigned, int gradeExecute);
	AForm(const AForm & copy);
	AForm & operator=(const AForm & other);
	~AForm(void);

	const std::string	&getName(void) const;
	bool				getSigned(void) const;
	int					getGradeSigned(void) const;
	int					getGradeExecute(void) const;

	void				beSigned(const Bureaucrat & bureaucrat);
	virtual void		execute(Bureaucrat const & executor) const = 0;

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

std::ostream	&operator<<(std::ostream & str, const AForm & form);

#endif
