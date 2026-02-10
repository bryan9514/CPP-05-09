/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:41:19 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/10 12:31:50 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

/* =========================== default constructor ============================ */
PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm()
{}

/* =========================== target constructor ============================= */
PresidentialPardonForm::PresidentialPardonForm(const std::string & target) :
	AForm("PresidentialPardonForm", target, 25, 5)
{}

/* =========================== copy constructor ============================= */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy) :
	AForm(copy)
{}

/* ======================== copy assignment operator ======================== */
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/* ================================ destructor ============================== */
PresidentialPardonForm::~PresidentialPardonForm(void)
{}

/* ============================ public methods ============================== */
void	PresidentialPardonForm::doAction(void) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
