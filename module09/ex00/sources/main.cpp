/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:28:16 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/14 16:11:09 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	return(0);
}
