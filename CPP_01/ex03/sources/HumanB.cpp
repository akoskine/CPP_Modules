/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:52:15 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/11 22:02:10 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

/************************* Constructors & Destructors *************************/

HumanB::HumanB(std::string name) : _name(name) {
}

HumanB::~HumanB() {
}

/********************************** Setters ***********************************/

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

/****************************** Public functions ******************************/

void	HumanB::attack() {
	if(this->_weapon == NULL)
		std::cout << _name << " attacks with their bare fists" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}