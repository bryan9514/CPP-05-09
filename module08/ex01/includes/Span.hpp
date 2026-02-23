/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:49:05 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/23 14:54:37 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>

class Span
{
private:
	std::vector<int>	_vec;
	unsigned int		_size;

	Span(void);
public:
	Span(unsigned int n);
	Span(const Span & copy);
	Span & operator=(const Span & other);
	~Span(void);

	void	addNumber(int newN);
	int		shortestSpan();
	int		longestSpan();

	std::vector<int>	getVec(void)
	{
		return (_vec);
	}
class FullVectorException : public std::exception
{
	virtual const char * what() const throw();
};

class InsufficientNumbersException : public std::exception
{
	virtual const char * what() const throw();
};
};

#endif
