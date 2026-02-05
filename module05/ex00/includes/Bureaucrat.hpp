/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:32:31 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/05 13:07:53 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade[150];

public:
	Bureaucrat(void);
	Bureaucrat(const std::string & name);
	Bureaucrat(const Bureaucrat & copy);
	Bureaucrat & operator=(const Bureaucrat & other);
	~Bureaucrat(void);
	
};

# endif
