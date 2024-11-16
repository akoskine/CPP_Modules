/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:18:47 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 04:44:16 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Dog.hpp"

/************************* Constructors & Destructors *************************/

Dog::Dog(): Animal("Dog"), _brain(new Brain()) {
	std::cout << "Dog default constructor called." << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& src): Animal(src._type), _brain(NULL) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = src;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
	delete this->_brain;
}

/********************************** Operators *********************************/

Dog&	Dog::operator=(const Dog& src) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

/*********************************** Getters **********************************/

Brain*	Dog::getBrain() const {
	return (this->_brain);
}

/****************************** Public functions ******************************/

void	Dog::makeSound() const {
	std::cout << this->_type << ": Woof! " << std::endl;
}