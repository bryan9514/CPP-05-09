/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:03:32 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/26 15:28:07 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

# define RST "\033[0m"
# define ERR "\033[0;91m"
# define WRN "\033[0;93m"
# define SUC "\033[0;92m"
# define INF "\033[0;96m"
# define INP "\033[0;94m"

template <typename T>
class MutantStack : public std::stack<T>
{
private:

public:
	MutantStack(void) {}
	MutantStack(const MutantStack & copy)
	{
		*this = copy;
	}
	MutantStack & operator=(const MutantStack & other)
	{
		if (this != &other)
			this->c = other.c;
		return (*this);
	}
	~MutantStack(void){}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin()
	{
		return (this->c.begin());
	}

	iterator end()
	{
		return (this->c.end());
	}

	const_iterator begin() const
	{
		return (this->c.begin());
	}

	const_iterator end() const
	{
		return (this->c.end());
	}
};


#endif

