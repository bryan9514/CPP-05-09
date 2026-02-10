/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:25:31 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/10 15:32:15 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

/* =========================== default constructor ============================ */
RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm()
{}

/* =========================== target constructor ============================= */
RobotomyRequestForm::RobotomyRequestForm(const std::string & target) :
	AForm("RobotomyRequestForm", target, 72, 45)
{}

/* =========================== copy constructor ============================= */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy) :
	AForm(copy)
{}

/* ======================== copy assignment operator ======================== */
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/* ================================ destructor ============================== */
RobotomyRequestForm::~RobotomyRequestForm(void)
{}

/* ============================ public methods ============================== */
void	RobotomyRequestForm::doAction(void) const
{
	int	status;

	std::cout << "🛠️ Brrrrrrrrr... Vrrrrrrr... 🔧" << std::endl;
	status = rand() % 2;
	if (status)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << getTarget() << "'s robotomization failed" << std::endl;

}
