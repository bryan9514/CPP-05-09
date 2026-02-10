/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:21:07 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/10 17:54:39 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
class AForm;

class Intern
{
private:

public:
	Intern(void);
	Intern(const Intern & copy);
	Intern & operator=(const Intern & other);
	~Intern(void);

	AForm*	factoryForm(std::string nameForm, std::string target);
};

#endif
