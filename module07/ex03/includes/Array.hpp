/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:48:59 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/21 17:00:35 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

# define RST "\033[0m"
# define ERR "\033[0;91m"
# define WRN "\033[0;93m"
# define SUC "\033[0;92m"
# define INF "\033[0;96m"
# define INP "\033[0;94m"

template <typename T>

class Array
{
private:
	T*				_arr;
	unsigned int	_size;

public:
	Array(void);
	Array(unsigned int n);
	Array(const Array & copy);
	Array & operator=(const Array & other);
	T & operator[](unsigned int n);
	const T & operator[](unsigned int n) const;
	~Array(void);

	unsigned int	size(void) const;

class indexIsOut : public std::exception
{
public:
	virtual const char * what() const throw();
};
};

#include "Array.tpp"

#endif
