/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:32:34 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/10 15:15:44 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string & target);
	ShrubberyCreationForm(const ShrubberyCreationForm & copy);
	ShrubberyCreationForm & operator=(const ShrubberyCreationForm & other);
	~ShrubberyCreationForm(void);
	
	void	doAction(void) const;
};

#endif
