/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 11:10:52 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/23 10:36:08 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>

# define RST "\033[0m"
# define ERR "\033[0;91m"
# define WRN "\033[0;93m"
# define SUC "\033[0;92m"
# define INF "\033[0;96m"
# define INP "\033[0;94m"


class	notOccurrenceIsFind : public std::exception
{
public:
	virtual const char * what()  const throw() {
		return ("No occurrences were found.");
	}
};

template <typename T>
typename T::iterator	easyfind(T & one, int two)
{
	for (typename T::iterator it = one.begin(); it != one.end(); it++)
		if (*it == two)
			return (it);
	throw notOccurrenceIsFind();
}

#endif
