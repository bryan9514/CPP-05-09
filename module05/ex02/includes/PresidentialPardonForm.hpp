/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:19:58 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/09 15:00:04 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string & target);
	PresidentialPardonForm(const PresidentialPardonForm & copy);
	PresidentialPardonForm & operator=(const PresidentialPardonForm & other);
	~PresidentialPardonForm(void);

	virtual void	execute(Bureaucrat const & executor) const;
};

#endif
