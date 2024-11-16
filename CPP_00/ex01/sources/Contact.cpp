/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:35:01 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/08 22:40:01 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Contact::Contact() {
}

Contact::~Contact() {
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

bool	Contact::areFilled(void) {
	if (this->_firstname.empty()
		|| this->_lastname.empty()
		|| this->_nickname.empty()
		|| this->_number.empty()
		|| this->_secret.empty())
		return (true);
	return (false);
}

bool	Contact::printSingleContact(void) {
	if (this->areFilled())
		return (false);
	std::cout	<< "| First name\t: "	<< this->getFirstname()	<< std::endl
				<< "| Last name\t: "	<< this->getLastname()	<< std::endl
				<< "| Nickname\t: "		<< this->getNickname()	<< std::endl
				<< "| Phone number\t: "	<< this->getNumber() 	<< std::endl
				<< "| Darkest secret: "	<< this->getSecret()	<< std::endl;
	return (true);
}

bool	Contact::setFirstname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	this->_firstname = str;
	return (true);
}

bool	Contact::setLastname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	this->_lastname = str;
	return (true);
}

bool	Contact::setNickname(std::string str) {
	if (str.empty()) {
		return (false);
	}
	this->_nickname = str;
	return (true);
}

bool	Contact::setNumber(std::string str) {
	if (str.empty()) {
		return (false);
	}
	this->_number = str;
	return (true);
}

bool	Contact::setSecret(std::string str) {
	if (str.empty()) {
		return (false);
	}
	this->_secret = str;
	return (true);
}

std::string const	Contact::getFirstname(void) const {
	return (this->_firstname);
}

std::string const	Contact::getLastname(void) const {
	return (this->_lastname);
}

std::string const	Contact::getNickname(void) const {
	return (this->_nickname);
}

std::string const	Contact::getNumber(void) const {
	return (this->_number);
}

std::string const	Contact::getSecret(void) const {
	return (this->_secret);
}