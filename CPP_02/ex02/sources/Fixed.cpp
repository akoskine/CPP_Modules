/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:57:23 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/16 16:11:01 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/************************* Constructors & Destructors *************************/

Fixed::Fixed() : _raw(0) {
}

Fixed::Fixed(const Fixed& src) {
	*this = src;
}

Fixed::Fixed(const int nValue) : _raw(nValue << _fractionalBits) {
}

Fixed::Fixed(const float fValue) : _raw(roundf(fValue * (1 << _fractionalBits))) {
}

Fixed::~Fixed() {
}

/********************************** Operators *********************************/

Fixed &	Fixed::operator=(const Fixed& src) {
	if (this != &src)
		this->_raw = src.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed& rhs) const {
	return (this->_raw > rhs.getRawBits());
}

bool	Fixed::operator<( Fixed const & rhs ) const {
	return (this->_raw < rhs.getRawBits());
}

bool	Fixed::operator>=( Fixed const & rhs ) const {
	return (this->_raw >= rhs.getRawBits());
}

bool	Fixed::operator<=( Fixed const & rhs ) const {
	return (this->_raw <= rhs.getRawBits());
}

bool	Fixed::operator==( Fixed const & rhs ) const {
	return (this->_raw == rhs.getRawBits());
}

bool	Fixed::operator!=( Fixed const & rhs ) const {
	return (this->_raw != rhs.getRawBits());
}

Fixed	Fixed::operator+( Fixed const & rhs ) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-( Fixed const & rhs ) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*( Fixed const & rhs ) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/( Fixed const & rhs ) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &	Fixed::operator++(void) {
	this->_raw += 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed	tmp(*this);
	++(*this);
	return (tmp);
}

Fixed &	Fixed::operator--() {
	this->_raw -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed	tmp(*this);
	--(*this);
	return (tmp);
}

/*********************************** Getters **********************************/

int	Fixed::getRawBits( void ) const {
	return (this->_raw);
}

/*********************************** Setters **********************************/

void	Fixed::setRawBits( int const raw ) {
	this->_raw = raw;
}

/****************************** Public functions ******************************/

int		Fixed::toInt( void ) const {
	return (this->_raw >> Fixed::_fractionalBits);	
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_raw / (1 << _fractionalBits));
}

Fixed&	Fixed::min(Fixed& lhs, Fixed& rhs) {
	if (lhs <= rhs)
		return (lhs);
	return (rhs);
}

Fixed&	Fixed::max(Fixed & lhs, Fixed & rhs) {
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	if ( lhs <= rhs )
		return ( lhs );
	return ( rhs );
}

const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

std::ostream& operator<<(std::ostream& os, const Fixed& nb) {
	os << nb.toFloat();
	return (os);
}