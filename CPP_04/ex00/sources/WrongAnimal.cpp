/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:42:34 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 00:42:39 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

/************************* Constructors & Destructors *************************/

WrongAnimal::WrongAnimal(): _type("Unknown WrongAnimal") {
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = src;
}

WrongAnimal::WrongAnimal(std::string const & type): _type(type) {
	std::cout << "WrongAnimal type constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

/********************************** Operators *********************************/

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src) {
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/*********************************** Getters **********************************/

std::string const &	WrongAnimal::getType(void) const {
	return (this->_type);
}

/****************************** Public functions ******************************/

void	WrongAnimal::makeSound() const {
	std::cout << this->_type << ": Unknown scream!" << std::endl;
}