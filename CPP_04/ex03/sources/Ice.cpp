/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:32:02 by akoskine          #+#    #+#             */
/*   Updated: 2024/02/06 20:19:59 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << "Ice default constructor called." << std::endl;
	return ;
}

Ice::Ice(Ice const& src) : AMateria("ice") {
	// std::cout << "Ice copy constructor called." << std::endl;
	*this = src;
}

Ice::~Ice() {
	// std::cout << "Ice destructor called." << std::endl;
}

Ice&	Ice::operator=(Ice const& src) {
	// std::cout << "Ice assignment operator called." << std::endl;
	this->_type = src._type;
	return (*this);
}

AMateria*	Ice::clone() const {
	AMateria*	tmpIce = new Ice();
	return (tmpIce);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* uses Ice spell and shoots an ice bolt at " << target.getName() << " *" << std::endl;
}