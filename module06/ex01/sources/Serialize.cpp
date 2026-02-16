/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Serialize.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:55:43 by brturcio          #+#    #+#             */
/*   Updated: 2026/02/16 11:39:56 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include <stdint.h>

/* =========================== default constructor ========================== */
Serialize::Serialize(void)
{}

/* =========================== copy constructor ============================= */
Serialize::Serialize(const Serialize & copy)
{
	*this = copy;
}

/* ==================== copy assignment operator (=) ======================== */
Serialize & Serialize::operator=(const Serialize & other)
{
	(void)other;
	return (*this);
}

/* ================================ destructor ============================== */
Serialize::~Serialize(void)
{}

/* ============================ public methods ============================== */
uintptr_t	Serialize::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
