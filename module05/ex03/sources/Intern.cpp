/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:21:17 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/10 17:54:29 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

Intern::Intern(void)
{}

Intern::Intern(const Intern & copy)
{
	(void)copy;
}

Intern & Intern::operator=(const Intern & other)
{
	(void)other;
	return (*this);
}

AForm*	Intern::factoryForm(std::string nameForm, std::string target)
{
	AForm*	ptr = NULL;


	return ();
}
