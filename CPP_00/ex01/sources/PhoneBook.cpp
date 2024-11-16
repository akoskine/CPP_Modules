/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:39:00 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/11 20:01:18 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

PhoneBook::PhoneBook() : _index(-1), _stop(false) {
}

PhoneBook::~PhoneBook() {
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

std::string	PhoneBook::_getContactInfo(std::string const str) {
	std::string	input;

	std::cout << "Submit " << str << ":" << std::endl << "> ";
	if (!std::getline(std::cin, input) || std::cin.eof()) {
		_stop = true;
		std::cout << std::endl;
		return(std::string());
	}
	return (input);
}

void	PhoneBook::_printColumnNames(void) {
	std::cout	<< "|----------|----------|----------|----------|" << std::endl
				<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++) {
		_printColumnContact(i);
	}
	std::cout << std::endl;
	return ;
}

void	PhoneBook::_printColumnContact(int const i) {
	if (this->_contacts[i].areFilled())
		return ;
	std::cout << "|" << std::setw(10) << i << "|";
	_printTrimmedContact(this->_contacts[i].getFirstname());
	_printTrimmedContact(this->_contacts[i].getLastname());
	_printTrimmedContact(this->_contacts[i].getNickname());
	std::cout	<< std::endl
				<< "|----------|----------|----------|----------|" << std::endl;
	return ;
}

void PhoneBook::_printTrimmedContact(std::string str) {
	if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << "|";
	return ;
}

bool	PhoneBook::_printIndexContact(std::string const input) {

	int	i;

	if (input.length() == 1 && std::isdigit(input[0])) {
		i = input[0] - '0';
		if (i >= 0 && i <= 7) {
			if (this->_contacts[i].printSingleContact())
				return (true);
			else {
				std::cout << "No contact in that index!" << std::endl;
				return (false);
			}
		}
	}
	std::cout << "This is not valid index. Please select between 0 - 7!" << std::endl;
	return (false);
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

bool 	PhoneBook::addContact(void) {
	std::string	input;

	_index++;
	if (_index > 7)
		_index = 0;
	std::cout << std::endl << "||------------ Submit Contact -------------||" << std::endl;
	while (!_stop) {
		input = _getContactInfo("a first name");
		if (_stop || this->_contacts[_index].setFirstname(input))
			break ;
	}
	while (!_stop) {
		input = _getContactInfo("a last name");
		if (_stop || this->_contacts[_index].setLastname(input))
			break ;
	}
	while (!_stop) {
		input = _getContactInfo("a nickname");
		if (_stop || this->_contacts[_index].setNickname(input))
			break ;
	}
	while (!_stop) {
		input = _getContactInfo("a phone number");
		if (_stop || this->_contacts[_index].setNumber(input))
			break ;
	}
	while (!_stop) {
		input = _getContactInfo("a darkest secret");
		if (_stop || this->_contacts[_index].setSecret(input))
			break ;
	}
	if (_stop) {
		_stop = false;
		return (false);
	}
	std::cout << "New contact acquired!" << std::endl;
	return (true);
}

bool	PhoneBook::searchContact(void) {
	std::string	input;

	std::cout << std::endl << "||---------------- Search -----------------||" << std::endl << std::endl;
	if (_index == -1) {
		std::cout << "No contacts. Use ADD first and then try again!" << std::endl;
		return (true);
	}
	this->_printColumnNames();
	while (input.empty() && !_stop)
		input = _getContactInfo("the index of the contact");
	if (_stop) {
		_stop = false;
		return (false);
	}
	this->_printIndexContact((std::string const)input);
	return (true);
}