/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:02:40 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/21 18:18:11 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstddef>

/* =========================== default constructor ========================== */
template <typename T>
Array<T>::Array(void) :
	_arr(NULL),
	_size(0)
{}

/* ======================== parameter constructor =========================== */
template <typename T>
Array<T>::Array(unsigned int n) :
	_arr(new T[n]),
	_size(n)
{}

/* =========================== copy constructor ============================= */
template <typename T>
Array<T>::Array(const Array<T> & copy) :
	_arr(NULL),
	_size(0)
{
	_size = copy._size;
	_arr = new T[copy._size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = copy._arr[i];
}

/* ==================== copy assignment operator (=) ======================== */
template <typename T>
Array<T> & Array<T>::operator=(const Array & other)
{
	if (this != &other) {
		delete[] _arr;
		_size = other._size;
		_arr = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			_arr[i] = other._arr[i];
	}
	return (*this);
}

/* ============================ operator ([]) =============================== */
template <typename T>
T & Array<T>::operator[](unsigned int n)
{
	if (n >= _size) {
		throw Array::indexIsOut();
	}
	return (_arr[n]);
}

template <typename T>
const T & Array<T>::operator[](unsigned int n) const
{
	if (n >= _size) {
		throw Array::indexIsOut();
	}
	return (_arr[n]);
}

/* ================================ destructor ============================== */
template <typename T>
Array<T>::~Array(void)
{
	if (_arr != NULL)
		delete [] _arr;
}

/* ================================= getters ================================ */
template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

/* ============================== exceptions ================================ */
template <typename T>
const char*	Array<T>::indexIsOut::what() const throw()
{
	return ("Invalid index");
}
