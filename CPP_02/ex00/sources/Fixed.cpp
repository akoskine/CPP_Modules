/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:58:31 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/15 17:02:50 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/************************* Constructors & Destructors *************************/

Fixed::Fixed() : _raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/********************************** Operators *********************************/

Fixed &	Fixed::operator=( Fixed const & src ) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &src)
		this->_raw = src.getRawBits();
	return ( *this );
}

/*********************************** Getters **********************************/

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_raw);
}

/*********************************** Setters **********************************/

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member funtion called." << std::endl;
	this->_raw = raw;
}