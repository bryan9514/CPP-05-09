/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:21:07 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/11 12:36:02 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <exception>
#include <string>
class AForm;

class Intern
{
private:

public:
	Intern(void);
	Intern(const Intern & copy);
	Intern & operator=(const Intern & other);
	~Intern(void);

	AForm*	makeForm(std::string nameForm, std::string target);
	AForm*	createShrubberyForm(std::string target);
	AForm*	createRobotomyForm(std::string target);
	AForm*	createPresidentialForm(std::string target);

class FormNotFoundException : public std::exception
{
public:
	const char* what() const throw();
};
};

#endif
