/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:54:20 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/11 21:58:44 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/************************* Constructors & Destructors *************************/

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon() {
}

/********************************** Getters ***********************************/

std::string	Weapon::getType() {
	return (_type);
}

/********************************** Setters ***********************************/

void	Weapon::setType(std::string type) {
	_type = type;
}