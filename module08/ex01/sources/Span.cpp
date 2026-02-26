/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:49:02 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/24 18:58:52 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdlib>

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
	_size = copy._size;
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

/* ================================= getters ================================ */
const std::vector<int>&	Span::getVec(void) const
{
	return (_vec);
}

/* ============================ public methods ============================== */
void	Span::addNumber(int newN)
{
	if (_vec.size() >= _size)
		throw FullVectorException();
	_vec.push_back(newN);
}

int	Span::longestSpan(void) const
{
	int	max = 0;

	if (_vec.size() <= 1)
		throw InsufficientNumbersException();
	std::vector<int>	tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	max = tmp[tmp.size() - 1] - tmp[0];
	return (max);
}

int	Span::shortestSpan(void) const
{
	int	min = 0;

	if (_vec.size() <= 1)
		throw InsufficientNumbersException();
	std::vector<int>	tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	min = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
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
