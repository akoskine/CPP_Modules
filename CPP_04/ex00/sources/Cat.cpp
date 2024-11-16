/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:22 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 00:35:58 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"

/************************* Constructors & Destructors *************************/

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat default constructor called." << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& src): Animal(src._type) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = src;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

/********************************** Operators *********************************/

Cat&	Cat::operator=(const Cat& src) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/****************************** Public functions ******************************/

void	Cat::makeSound() const {
	std::cout << this->_type << ": Meow! " << std::endl;
}