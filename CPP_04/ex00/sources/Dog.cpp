/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:18:47 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 00:35:53 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Dog.hpp"

/************************* Constructors & Destructors *************************/

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog default constructor called." << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& src): Animal(src._type) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = src;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

/********************************** Operators *********************************/

Dog&	Dog::operator=(const Dog& src) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/****************************** Public functions ******************************/

void	Dog::makeSound() const {
	std::cout << this->_type << ": Woof! " << std::endl;
}