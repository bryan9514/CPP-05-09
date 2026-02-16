/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Serialize.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:55:39 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/16 11:09:11 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <string>
#include <stdint.h>

struct Data
{
	int			_id;
	std::string	_name;
};

class  Serialize
{
private:
	 Serialize(void);
	 Serialize(const Serialize & copy);
	 Serialize & operator=(const Serialize & other);
	 ~Serialize(void);

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif
