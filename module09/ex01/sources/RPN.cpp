/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:09:10 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/23 11:27:17 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stdexcept>
#include <cctype>

RPN::RPN(void)
{}

RPN::RPN(const RPN & copy) :
	_stack(copy._stack)
{}

RPN &	RPN::operator=(const RPN & other)
{
	if (this != &other) {
		_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN(void)
{}

bool RPN::isOperator(const std::string & token)
{
	if (token == "+" || token == "-" || token == "*" || token == "/")
		return (true);
	return (false);
}

int RPN::applyOperation(int a, int b, const std::string & op)
{
	int	result;

	if (op == "+")
		result = a + b;
	else if (op == "-")
		result = a - b;
	else if (op == "*")
		result = a * b;
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error");
		result = a / b;
	}
	else
		throw std::runtime_error("Error");
	return (result);
}

void	RPN::tokenizer(std::string & tokens, std::string & token)
{
	size_t	pos;

	while (!tokens.empty() && tokens[0] == ' ')
		tokens.erase(0, 1);
	pos = tokens.find(" ");
	if (pos != std::string::npos) {
		token = tokens.substr(0, pos);
		tokens.erase(0, pos + 1);
	}
	else {
		token = tokens;
		tokens.clear();
	}
}

void	RPN::calculOperation(std::string & currentToken)
{
	int	b;
	int	a;

	if (_stack.size() < 2)
			throw std::runtime_error("Error");
	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	_stack.push(applyOperation(a, b, currentToken));
}

void RPN::process(const std::string & input)
{
	std::string	tokens = input;
	std::string	currentToken;

	while (!tokens.empty())
	{
		tokenizer(tokens, currentToken);
		if (currentToken.length() != 1)
    		throw std::runtime_error("Error");
		if (std::isdigit(currentToken[0]))
			_stack.push(currentToken[0] - '0');
		else if (isOperator(currentToken))
			calculOperation(currentToken);
		else
			throw std::runtime_error("Error");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	std::cout << _stack.top() << std::endl;
}
