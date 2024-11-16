/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:31:55 by akoskine          #+#    #+#             */
/*   Updated: 2024/02/06 20:19:42 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(Cure const& src) : AMateria("cure") {
	// std::cout << "Cure copy constructor called." << std::endl;
	*this = src;
}

Cure::~Cure() {
	// std::cout << "Cure destructor called." << std::endl;
}

Cure&	Cure::operator=(Cure const& src) {
	// std::cout << "Cure assignment operator called." << std::endl;
	this->_type = src._type;
	return (*this);
}

AMateria*	Cure::clone() const {
	AMateria*	tmpCure = new Cure();
	return (tmpCure);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* uses Cure spell and heals " << target.getName() << "'s wounds *" << std::endl;
}
