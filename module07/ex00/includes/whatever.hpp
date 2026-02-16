/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:53:14 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/16 22:23:04 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# define RST "\033[0m"
# define ERR "\033[0;91m"
# define WRN "\033[0;93m"
# define SUC "\033[0;92m"
# define INF "\033[0;96m"
# define INP "\033[0;94m"

template <typename A>
void	swap(A &x , A &y)
{
	A	tmp = x;
	x = y;
	y = tmp;
}

template <typename B>
B	min(B x, B y)
{
	if (x == y)
		return (y);
	return ((x < y) ? x : y);
}

template <typename C>
C	max(C x, C y)
{
	if (x == y)
		return (y);
	return ((x > y) ? x : y);
}

#endif
