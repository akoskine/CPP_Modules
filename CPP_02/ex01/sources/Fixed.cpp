/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:07:09 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/15 20:16:28 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/************************* Constructors & Destructors *************************/

Fixed::Fixed() : _raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed::Fixed(const int nValue) : _raw(nValue << _fractionalBits) {
	std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float fValue) : _raw(roundf(fValue * (1 << _fractionalBits))) {
	std::cout << "Float constructor called." << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called." << std::endl;
}

/********************************** Operators *********************************/

Fixed&	Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &src)
		this->_raw = src.getRawBits();
	return (*this);
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

/****************************** Public functions ******************************/

int		Fixed::toInt( void ) const {
	return (this->_raw >> Fixed::_fractionalBits);	
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_raw / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& nb) {
	os << nb.toFloat();
	return (os);
}