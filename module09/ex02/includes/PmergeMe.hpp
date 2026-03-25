/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:29:20 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/25 16:31:25 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <ctime>
#include <string>
#include <vector>
#include <deque>

# define RST "\033[0m"
# define ERR "\033[0;91m"
# define WRN "\033[0;93m"
# define SUC "\033[0;92m"
# define INF "\033[0;96m"
# define INP "\033[0;94m"
# define MAG "\033[0;95m" 
# define BLU "\033[0;34m"  
# define CYA "\033[0;36m"

enum TypeErrors
{
	MISSINGARGS,
	MAXARG,
	ARGEMPTY,
	MULTIPLE_SIGNS,
	MISSINGNUMBER,
	INVALIDARG,
	NUMBERMAX
};

enum TypeContain
{
	VECTOR,
	DEQUE
};

class	PmergeMe
{
private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;
	double				_timeVec;
	double				_timeDeq;

	/* =================== parsing ======================= */
	void	checkSign(const std::string & token, size_t & i);
	void	isValid(const std::string & token);
	void	convertAndSaveToken(const std::string & token);

	/* =================== vector ======================= */
	void	makePairsVector(std::vector<int> & input, std::vector<std::pair<int, int> > & pairsVector,
							   int & leftover, bool & hasLeftover);
	void	getMaxMinVector(std::vector<std::pair<int, int> > & pairsVector, std::vector<int> & max, std::vector<int> & min);
	void	insertFirst(std::vector<int> & mainVector, int value);
	std::vector<size_t>	buildJacobOrderVector(size_t n);
	void	binaryInsertJacobOrder(std::vector<int> & max, std::vector<int> & min);
	void	fordJohnsonSortVector(std::vector<int> & input);

	/* =================== deque ======================= */
	void	makePairsDeque(std::deque<int> & input, std::deque<std::pair<int, int> > & pairsDeque,
							   int & leftover, bool & hasLeftover);
	void	getMaxMinDeque(std::deque<std::pair<int, int> > & pairsDeque, std::deque<int> & max, std::deque<int> & min);
	void	insertFirst(std::deque<int> & mainDeque, int value);
	std::deque<size_t>	buildJacobOrderDeque(size_t n);
	void	binaryInsertJacobOrder(std::deque<int> & max, std::deque<int> & min);
	void	fordJohnsonSortDeque(std::deque<int> & input);

	/* =================== time ======================= */
	void	calculteTime(clock_t start, clock_t end, TypeContain contain);

public:
	PmergeMe(void);
	PmergeMe(const PmergeMe & copy);
	PmergeMe & operator=(const PmergeMe & other);
	~PmergeMe(void);

	void	checkInput(int ac, char **av);
	void	printfInput(int ac, char **av);
	void	printfInputSort();
	void	sortVector(void);
	void	sortDeque(void);
	void	printfTime();
};

void	controlErrors(TypeErrors error, const std::string & token);

#endif
