/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:44:19 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/25 16:40:56 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <climits>
#include <cstddef>
#include <ctime>
#include <cwchar>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <iostream>

/* =========================== default constructor ========================== */
PmergeMe::PmergeMe(void) :
	_vec(),
	_deq()
{}

/* =========================== copy constructor ============================= */
PmergeMe::PmergeMe(const PmergeMe & copy) :
	_vec(copy._vec),
	_deq(copy._deq)
{}

/* ==================== copy assignment operator (=) ======================== */
PmergeMe & PmergeMe::operator=(const PmergeMe & other)
{
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

/* ================================ destructor ============================== */
PmergeMe::~PmergeMe(void)
{}


/* ================================= printfs ================================ */
void controlErrors(TypeErrors error, const std::string & token)
{
	std::string msg = "Error";

	if (error == MISSINGARGS)
		msg = "Error: no arguments provided";
	else if (error == MAXARG)
		msg = "Error: limit of arguments";
	else if (error == ARGEMPTY)
		msg = "Error: empty argument detected";
	else if (error == MULTIPLE_SIGNS)
		msg = "Error: invalid number (multiple sign characters)";
	else if (error == MISSINGNUMBER)
		msg = "Error: invalid number (sign without digits)";
	else if (error == INVALIDARG)
		msg = "Error: invalid input (only positive integers allowed)";
	else if (error == NUMBERMAX)
		msg = "Error: integer overflow (out of range)";
	if (!token.empty())
		msg += " -> [" + token + "]";
    throw std::runtime_error(msg);
}

void	PmergeMe::printfInputSort()
{
	std::cout << SUC << "After: ";
	
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i];
		if (i != _vec.size() - 1)
			std::cout << " ";
	}
	std::cout << RST << std::endl;
}


void	PmergeMe::printfInput(int ac, char **av)
{
	std::cout << WRN << "Before: ";
	
	for (int i = 1; i < ac; i++)
	{
		std::cout << av[i];
		if (i != ac - 1)
			std::cout << " ";
	}
	std::cout << RST << std::endl;
}

void	PmergeMe::printfTime()
{
	std::cout << INF << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << _timeVec << " us" << RST << std::endl;
	std::cout << INP << "Time to process a range of " << _deq.size()
		<< " elements with std::deque : " << _timeDeq << " us" << RST << std::endl;
}

/* ================================= time ================================ */
void	PmergeMe::calculteTime(clock_t start, clock_t end, TypeContain contain)
{
	if (contain == VECTOR)
		_timeVec = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
	else if (contain == DEQUE)
		_timeDeq = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}


/* ================================= parsing ================================ */
void	PmergeMe::checkSign(const std::string & token, size_t & i)
{
	if (token[0] == '+' || token[0] == '-')
    	i = 1;
	if (i == token.size())
		controlErrors(MISSINGNUMBER, token);
}

void	PmergeMe::isValid(const std::string & token)
{
	size_t	i = 0;

	if (token.empty())
		controlErrors(ARGEMPTY, token);
	checkSign(token, i);
	while (i < token.size()) {
		if (!std::isdigit(token[i]))
			controlErrors(INVALIDARG, token);
		i++;
	}
}

void	PmergeMe::convertAndSaveToken(const std::string & token)
{
	long	longValue;
	int		intValue;

	longValue = std::strtol(token.c_str(), NULL, 10);
	if (longValue < 0 || longValue > INT_MAX)
		controlErrors(NUMBERMAX, token);
	intValue = static_cast<int>(longValue);
	_vec.push_back(intValue);
	_deq.push_back(intValue);
}


void	PmergeMe::checkInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++) {
		std::string	token = av[i];
		
		isValid(token);
		convertAndSaveToken(token);
	}
}


/* ========================================= Vector ====================================================*/
void	PmergeMe::makePairsVector(std::vector<int> & input, std::vector<std::pair<int, int> > & pairsVector,
							   int & leftover, bool & hasLeftover)
{
	for (size_t i = 0; i < input.size(); i += 2) {
		if (i + 1  < input.size()) {
			int a = input[i];
			int b = input[i + 1];
			if (a > b)
				std::swap(a, b);
			pairsVector.push_back(std::make_pair(a, b));
		}
		else {
			leftover = input[i];
			hasLeftover = true;
		}
	}
}

void	PmergeMe::getMaxMinVector(std::vector<std::pair<int, int> > & pairsVector, std::vector<int> & max, std::vector<int> & min)
{
	for (size_t i = 0; i < pairsVector.size(); i++) {
		max.push_back(pairsVector[i].second);
		min.push_back(pairsVector[i].first);
	}
}

void	PmergeMe::insertFirst(std::vector<int> & mainVector, int value)
{
	size_t	left = 0;
	size_t	right = mainVector.size();
	size_t	mid = 0;

	while (left < right) {
		mid = (left + right) / 2;
		if (mainVector[mid] < value)
			left = mid + 1;
		else
		 	right = mid;
	}
	mainVector.insert(mainVector.begin() + left, value);
}

std::vector<size_t>	PmergeMe::buildJacobOrderVector(size_t n)
{
	std::vector<size_t>	orden;

	if (n == 0)
		return (orden);
	orden.push_back(0);
	for (size_t i = 1; i < n; i += 2){
		if (i + 1 < n)
			orden.push_back(i + 1);
		orden.push_back(i);
	}
	return (orden);
}

void	PmergeMe::binaryInsertJacobOrder(std::vector<int> & max, std::vector<int> & min)
{
	size_t				index;
	std::vector<size_t>	order = buildJacobOrderVector(min.size());
	
	for (size_t i = 0; i < order.size(); i++) {
		index = order[i];
		insertFirst(max, min[index]);
	}
}

void	PmergeMe::fordJohnsonSortVector(std::vector<int> & input)
{
	std::vector<std::pair<int, int> >	pairsVector;
	std::vector<int>					min;
	std::vector<int>					max;
	int									leftover = 0;
	bool								hasLeftover = false;

	if (input.size() <= 1)
		return ;
	makePairsVector(input, pairsVector, leftover, hasLeftover);
	getMaxMinVector(pairsVector, max, min);
	fordJohnsonSortVector(max);
	binaryInsertJacobOrder(max, min);
	if (hasLeftover)
		insertFirst(max, leftover);
	input = max;
}

void	PmergeMe::sortVector(void)
{
	clock_t	start, end;

	start = clock();
	fordJohnsonSortVector(_vec);
	end = clock();
	calculteTime(start, end, VECTOR);
}

/* ========================================= deque ====================================================*/
void	PmergeMe::makePairsDeque(std::deque<int> & input, std::deque<std::pair<int, int> > & pairsDeque,
							   int & leftover, bool & hasLeftover)
{
	for (size_t i = 0; i < input.size(); i += 2) {
		if (i + 1  < input.size()) {
			int a = input[i];
			int b = input[i + 1];
			if (a > b)
				std::swap(a, b);
			pairsDeque.push_back(std::make_pair(a, b));
		}
		else {
			leftover = input[i];
			hasLeftover = true;
		}
	}
}

void	PmergeMe::getMaxMinDeque(std::deque<std::pair<int, int> > & pairsDeque, std::deque<int> & max, std::deque<int> & min)
{
	for (size_t i = 0; i < pairsDeque.size(); i++) {
		max.push_back(pairsDeque[i].second);
		min.push_back(pairsDeque[i].first);
	}
}

void	PmergeMe::insertFirst(std::deque<int> & mainDeque, int value)
{
	size_t	left = 0;
	size_t	right = mainDeque.size();
	size_t	mid = 0;

	while (left < right) {
		mid = (left + right) / 2;
		if (mainDeque[mid] < value)
			left = mid + 1;
		else
		 	right = mid;
	}
	mainDeque.insert(mainDeque.begin() + left, value);
}

std::deque<size_t>	PmergeMe::buildJacobOrderDeque(size_t n)
{
	std::deque<size_t>	orden;

	if (n == 0)
		return (orden);
	orden.push_back(0);
	for (size_t i = 1; i < n; i += 2){
		if (i + 1 < n)
			orden.push_back(i + 1);
		orden.push_back(i);
	}
	return (orden);
}

void	PmergeMe::binaryInsertJacobOrder(std::deque<int> & max, std::deque<int> & min)
{
	size_t				index;
	std::deque<size_t>	order = buildJacobOrderDeque(min.size());
	
	for (size_t i = 0; i < order.size(); i++) {
		index = order[i];
		insertFirst(max, min[index]);
	}
}

void	PmergeMe::fordJohnsonSortDeque(std::deque<int> & input)
{
	std::deque<std::pair<int, int> >	pairsDeque;
	std::deque<int>						min;
	std::deque<int>						max;
	int									leftover = 0;
	bool								hasLeftover = false;

	if (input.size() <= 1)
		return ;
	makePairsDeque(input, pairsDeque, leftover, hasLeftover);
	getMaxMinDeque(pairsDeque, max, min);
	fordJohnsonSortDeque(max);
	binaryInsertJacobOrder(max, min);
	if (hasLeftover)
		insertFirst(max, leftover);
	input = max;
}

void	PmergeMe::sortDeque(void)
{
	clock_t	start, end;

	start = clock();
	fordJohnsonSortDeque(_deq);
	end = clock();
	calculteTime(start, end, DEQUE);
}

