/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:23:57 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/10 15:36:59 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string & target);
	RobotomyRequestForm(const RobotomyRequestForm & copy);
	RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
	~RobotomyRequestForm(void);
	
	void	doAction(void) const;
};

#endif
