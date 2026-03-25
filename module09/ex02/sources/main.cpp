/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:37:41 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/25 15:57:14 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int	main(int ac, char **av)
{

	try {
		if (ac == 1)
			controlErrors(MISSINGARGS, "");
		else if (ac - 1 > 3000)
			controlErrors(MAXARG, "3000");
		PmergeMe	pMergeMe;

		pMergeMe.checkInput(ac, av);
		pMergeMe.printfInput(ac, av);
		pMergeMe.sortVector();
		pMergeMe.sortDeque();
		pMergeMe.printfInputSort();
		pMergeMe.printfTime();
	} catch (const std::exception & e) {
		std::cerr << ERR << e.what() << RST << std::endl;
		return (1);
	}
	return (0);
}
