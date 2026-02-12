/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:33:28 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/12 17:38:49 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cctype>

/* =========================== default constructor ========================== */
ScalarConverter::ScalarConverter(void)
{}

/* =========================== copy constructor ============================= */
ScalarConverter::ScalarConverter(const ScalarConverter & copy)
{
	*this = copy;
}

/* ==================== copy assignment operator (=) ======================== */
ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other)
{
	(void)other;
	return (*this);
}

/* ================================ destructor ============================== */
ScalarConverter::~ScalarConverter(void)
{}

/* ============================ public methods ============================== */
void	ScalarConverter::convert(const std::string argum)
{

}


/* ============================== exceptions ================================ */
const char*	ScalarConverter::BadNumberArguments::what() const  throw()
{
	return ("Invalid number of arguments");
}

