/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:49:05 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/24 18:59:03 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <iterator>
#include <vector>

# define RST "\033[0m"
# define ERR "\033[0;91m"
# define WRN "\033[0;93m"
# define SUC "\033[0;92m"
# define INF "\033[0;96m"
# define INP "\033[0;94m"

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

	template <typename T>
	void	insertRange(T begin, T end)
	{
		size_t	distance = static_cast<size_t>(std::distance(begin, end)) ;

		if (_vec.size() + distance > _size)
			throw FullVectorException();
		_vec.insert(_vec.end(), begin, end);
	}
	void	addNumber(int newN);
	int		shortestSpan() const;
	int		longestSpan() const;
	
	const std::vector<int> &	getVec(void) const;
	
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
