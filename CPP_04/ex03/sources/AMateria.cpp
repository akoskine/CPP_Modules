/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:31:46 by akoskine          #+#    #+#             */
/*   Updated: 2024/02/06 20:18:50 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown") {
	// std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(AMateria const& src) : _type(src._type) {
	// std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
	// std::cout << "AMateria type constructor called." << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "AMateria destructor called." << std::endl;
}

AMateria&	AMateria::operator=(AMateria const& src) {
	// std::cout << "AMateria assignment operator overload called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* Unspecified spell is being used against"
		<< target.getName() << " *" << std::endl;
}

std::string const&	AMateria::getType() const {
	return (this->_type);
}