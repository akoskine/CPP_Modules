/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:39:16 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 00:41:07 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

/************************* Constructors & Destructors *************************/

Animal::Animal(): _type("Unknown animal") {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(Animal const & src) {
	std::cout << "Animal copy constructor called." << std::endl;
	*this = src;
}

Animal::Animal(std::string const & type): _type(type) {
	std::cout << "Animal type constructor called." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

/********************************** Operators *********************************/

Animal &	Animal::operator=(Animal const & src) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/*********************************** Getters **********************************/

std::string const &	Animal::getType(void) const {
	return (this->_type);
}

/****************************** Public functions ******************************/

void	Animal::makeSound() const {
	std::cout << this->_type << ": Unknown scream!" << std::endl;
}