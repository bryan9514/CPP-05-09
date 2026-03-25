/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:08:16 by brturcio          #+#    #+#             */
/*   Updated: 2026/03/23 11:10:23 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

# define RST "\033[0m"
# define ERR "\033[0;91m"
# define WRN "\033[0;93m"
# define SUC "\033[0;92m"
# define INF "\033[0;96m"
# define INP "\033[0;94m"

class RPN
{
private:
	std::stack<int> _stack;

	bool	isOperator(const std::string & token);
	int		applyOperation(int a, int b, const std::string & op);
	void	tokenizer(std::string & tokens, std::string & token);
	void	calculOperation(std::string & currentToken);

public:
	RPN(void);
	RPN(const RPN & copy);
	RPN & operator=(const RPN & other);
	~RPN(void);

	void	process(const std::string & input);
};

#endif
