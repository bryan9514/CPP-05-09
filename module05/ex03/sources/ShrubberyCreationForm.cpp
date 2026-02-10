/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:34:53 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/10 15:23:17 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>

/* =========================== default constructor ============================ */
ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm()
{}

/* =========================== target constructor ============================= */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) :
	AForm("ShrubberyCreationForm", target, 145, 137)
{}

/* =========================== copy constructor ============================= */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy) :
	AForm(copy)
{}

/* ======================== copy assignmeno operator ======================== */
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/* ================================ destructor ============================== */
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

/* ============================ public methods ============================== */
void	ShrubberyCreationForm::doAction(void) const
{
	std::ofstream	file;
	std::string		fileName;

	fileName = getTarget() + "_shrubbery";
	file.open(fileName.c_str());

	if (file.fail())
		return ;
	file << "      /\\     " << std::endl;
	file << "     /**\\    " << std::endl;
	file << "    /****\\   " << std::endl;
	file << "   /******\\  " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;

	file.close();
}
