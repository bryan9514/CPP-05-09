/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:32:31 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/10 11:19:05 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <string>
class AForm;

/* ========== RESET ========== */
# define RST "\033[0m"

/* ============ STILES ===============*/
# define ERR "\033[0;91m" // Error (red)
# define WRN "\033[0;93m" // Warning (yellow)
# define SUC "\033[0;92m" // Success (green)
# define INF "\033[0;96m" // Info (cian)
# define INP "\033[0;94m" // Input (blue)

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(void);
	Bureaucrat(const std::string & name, int grade);
	Bureaucrat(const Bureaucrat & copy);
	Bureaucrat	&operator=(const Bureaucrat & other);
	~Bureaucrat(void);

	const std::string &getName(void) const;
	int			getGrade(void) const;
	
	void		increaseGrade(void);
	void		decreaseGrade(void);

	void		signAForm(AForm & form);
	void		executeForm(AForm const & form) const;

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

std::ostream	&operator<<(std::ostream & str, const Bureaucrat & bureaucrat);

# endif
