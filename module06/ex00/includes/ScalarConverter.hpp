/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:33:22 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/12 15:49:51 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <exception>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter & copy);
	ScalarConverter & operator=(const ScalarConverter & other);
	~ScalarConverter(void);

	static void	intConvert(int );
	static void	floatConvert(const )

public:

	static void	convert(const std::string argum);

class BadNumberArguments : public std::exception
{
public:
	virtual const char * what() const throw();
};
};

#endif
