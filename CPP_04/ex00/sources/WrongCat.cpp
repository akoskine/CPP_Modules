/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:33:48 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 00:39:07 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongCat.hpp"

/************************* Constructors & Destructors *************************/

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called." << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal(src._type) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = src;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

/********************************** Operators *********************************/

WrongCat&	WrongCat::operator=(const WrongCat& src) {
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

/****************************** Public functions ******************************/

void	WrongCat::makeSound() const {
	std::cout << this->_type << ": Meawowawiu! " << std::endl;
}