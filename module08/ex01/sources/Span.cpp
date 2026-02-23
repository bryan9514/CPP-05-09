/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:49:02 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/23 15:46:41 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* =========================== default constructor ========================== */
Span::Span(void) :
	_vec(0),
	_size(0)
{}

/* ======================== parameter constructor =========================== */
Span::Span(unsigned int n) :
	_vec(0),
	_size(n)
{}

/* =========================== copy constructor ============================= */
Span::Span(const Span & copy)
{
	_vec = copy._vec;
}

/* ==================== copy assignment operator (=) ======================== */
Span & Span::operator=(const Span & other)
{
	if (this != &other) {
		_vec = other._vec;
		_size = other._size;
	}
	return (*this);
}

/* ================================ destructor ============================== */
Span::~Span(void)
{}

/* ============================ public methods ============================== */
void	Span::addNumber(int newN)
{
	if (_vec.size() >= _size)
		throw FullVectorException();
	_vec.push_back(newN);
}

int	Span::longestSpan(void)
{
	int	max = 0;
	
	for (unsigned int i = 0; i < _size; i++) {
		for (unsigned int j = i + 1; j < _size - 1 ; j++) {
			if (_vec[i] > _vec[j])
				max = _vec[i];
			else
				max = _vec[j];
		}
	}
	return (max);
}


/* ============================== exceptions ================================ */
const char * Span::FullVectorException::what() const throw()
{
	return ("Cannot add number: span is already full.");
}

const char * Span::InsufficientNumbersException::what() const throw()
{
	return ("Insufficient elements to calculate span.");
}
