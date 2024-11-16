/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:22 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 05:06:57 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"

/************************* Constructors & Destructors *************************/

Cat::Cat(): AAnimal(), _brain(new Brain()) {
	std::cout << "Cat default constructor called." << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& src): AAnimal(), _brain(NULL) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = src;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
	delete this->_brain;
}

/********************************** Operators *********************************/

Cat&	Cat::operator=(const Cat& src) {
	std::cout << "Cat copy assignment operator called." << std::endl;
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

Brain*	Cat::getBrain() const {
	return (this->_brain);
}

/****************************** Public functions ******************************/

void	Cat::makeSound() const {
	std::cout << this->_type << ": Meow! " << std::endl;
}