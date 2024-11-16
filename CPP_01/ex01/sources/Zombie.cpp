/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:12 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/10 20:06:53 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

/************************* Constructors & Destructors *************************/

Zombie::Zombie() {
}

Zombie::Zombie(std::string str) : _name(str) {
	std::cout << "Zombie called " << this->_getName() << " appeared!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie called " << this->_getName() << " died!" << std::endl;
}

/********************************** Getters ***********************************/

std::string Zombie::_getName() {
	return (this->_name);
}

/********************************** Setters ***********************************/

void	Zombie::zombieName(std::string const name, int i) {
	char c;
	c = 65 + i;
	this->_name = name + c;
}

/****************************** Public functions ******************************/

void	Zombie::announce( void ) {
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
