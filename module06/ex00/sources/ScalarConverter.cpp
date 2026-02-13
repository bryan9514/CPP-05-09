/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:33:28 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/13 17:08:44 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cerrno>
#include <string>

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

/* ============================== exceptions ================================ */
const char*	ScalarConverter::BadNumberArguments::what() const  throw()
{
	return ("Invalid number of arguments");
}

const char*	ScalarConverter::IsNotInputValid :what() const throw()
{
	return ("Input is not valid");
}

const char*	ScalarConverter::InputEmpty:what() const throw()
{
	return ("Input empty");
}

/* ============================ public methods ============================== */
static void	printPseudo(const std::string & charResult, const std::string & intResult, 
		const std::string & floatResult, const std::string & doubleResult)
{
		std::cout << "char: " << charResult << std::endl;
		std::cout << "int: " << intResult << std::endl;
		std::cout << "float: " << floatResult << std::endl;
		std::cout << "double: " << doubleResult << std::endl;

}
static int	isPseudo(const std::string & argum)
{
	if (argum == "nan") {
		printPseudo("impossible", "impossible", "nanf", "nan");
		return (1);
	}
	else if (argum == "nanf") {
		printPseudo("impossible", "impossible", "nanf", "nan");
		return (1);
	}
	else if (argum == "+inf") {
		printPseudo("impossible", "impossible", "+inff", "+inf");
		return (1);
	}
	else if (argum == "+inff") {
		printPseudo("impossible", "impossible", "+inff", "+inf");
		return (1);
	}
	else if (argum == "-inf") {
		printPseudo("impossible", "impossible", "-inff", "-inf");
		return (1);
	}
	else if (argum == "-inff") {
		printPseudo("impossible", "impossible", "-inff", "-inf");
		return (1);
	}
	return (0);
}

static void	printAll(std::string & charResult, int intResult,
		float floatResult, double doubleResult)
{
	std::cout << "char: " << charResult << std::endl;
	std::cout << "int: " << intResult << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << floatResult << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleResult << std::endl;
}

static int	handleInt(long numLong)
{
	std::string	charResult;
	int	num = static_cast<int>(numLong);

	if (num < 0 || num > 127)
		charResult = "impossible";
	else if ((num >= 0 && num <= 31) || num == 127)
		charResult = "Non displayable";
	else {
	 	charResult = "'";
		charResult += static_cast<char>(num);
		charResult += "'";
	}
	printAll(charResult, num, static_cast<float>(num), static_cast<double>(num));
	return (1);
}

static int	isInt(const std::string & argum)
{
	errno = 0;
	char	*end;
	long	numLong = std::strtol(argum.c_str(), &end, 10);
	
	if (errno == ERANGE)
		return (0);
	if (end == argum.c_str())
		return 0;
	if (*end != '\0')
		return (0);	
	if (numLong < INT_MIN || numLong > INT_MAX)
		return (0);
	handleInt(numLong);
	return (1);
}

static int	handleFloat(double num)
{
	std::string	charResult;

	if (num < 0 || num > 127)
		charResult = "impossible";
	else if ((num >= 0 && num <= 31) || num == 127)
		charResult = "Non displayable";
	else {
		charResult = "'";
		charResult += static_cast<char>(num);
		charResult += "'";
	}
	printAll(charResult, static_cast<int>(num), static_cast<float>(num), num);
	return (1);
}

static int	isFloat(const std::string & argum)
{
	errno = 0;
	char	*end;
	double	numDouble;

	if (argum[argum.size() -1] != 'f')
		return (0);
	numDouble = std::strtod(argum.c_str(), &end);
	if (errno == ERANGE)
		return (0);
	//Después del número convertido, el siguiente carácter debe ser exactamente 'f'
	if (*end != 'f')
		return (0);
	//verifica que no haya nada después de la f
	if (*(end + 1) != '\0')
		return (0);
	handleFloat(numDouble);
	return (1);
}

static int	handleDouble(double num)
{
	std::string	charResult;

	if (num < 0 || num > 127)
		charResult = "impossible";
	else if ((num >= 0 && num <= 31) || num == 127)
		charResult = "Non displayable";
	else {
		charResult = "'";
		charResult += static_cast<char>(num);
		charResult += "'";
	}
	printAll(charResult, static_cast<int>(num), static_cast<float>(num), num);
	return (1);
}

static int	isDouble(const std::string & argum)
{
	errno = 0;
	char	*end;
	double	numDouble = std::strtod(argum.c_str(), &end);

	if (errno == ERANGE)
		return (0);
	if (*end != '\0')
		return (0);
	handleDouble(numDouble);
	return (1);
}

static int	isChar(const std::string & argum)
{
	if (argum.size())
}

void	ScalarConverter::convert(const std::string & argum)
{
	if (argum.empty())
		throw ScalarConverter::InputEmpty();
	if (isPseudo(argum))
		return ;
	if (isInt(argum))
		return ;
	if (isFloat(argum))
		return ;
	if (isDouble(argum))
		return ;
	if (isChar(argum))
		return ;
	throw ScalarConverter::IsNotInputValid();
}

