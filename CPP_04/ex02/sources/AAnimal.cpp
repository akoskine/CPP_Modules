/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 04:56:38 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 14:46:55 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AAnimal.hpp"

/************************* Constructors & Destructors *************************/

AAnimal::AAnimal(): _type("Unknown animal") {
	std::cout << "Animal default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) {
	std::cout << "Animal copy constructor called." << std::endl;
	*this = src;
}

AAnimal::~AAnimal() {
	std::cout << "Animal destructor called." << std::endl;
}

/********************************** Operators *********************************/

AAnimal &	AAnimal::operator=(const AAnimal& src) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/****************************** Public functions ******************************/

void	AAnimal::makeSound() const {
	std::cout << this->_type << ": Unknown scream!" << std::endl;
}