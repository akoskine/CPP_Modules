/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:55:25 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/16 18:30:30 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

/************************* Constructors & Destructors *************************/

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10),
	_energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0) {
	std::cout << "Constructor called" << std::endl;
	std::cout << "ClapTrap named " << name << " was called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destuctor called" << std::endl;
	std::cout << "ClapTrap named " << this->_name
		<< " was destroyed" << std::endl;
}

/********************************** Operators *********************************/

ClapTrap&	ClapTrap::operator=(const ClapTrap& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

/*********************************** Getters **********************************/

std::string	ClapTrap::getName() const {
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints() const {
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const {
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const {
	return (this->_attackDamage);
}

/****************************** Public functions ******************************/

void	ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout	<< "ClapTrap named " << this->_name
					<< " can't attack, because it does not have HP."
					<< std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout	<< "ClapTrap named " << this->_name
					<< " can't attack, because it does not have Energy."
					<< std::endl;
		return ;
	}
	if (target == this->_name)
		std::cout	<< "ClapTrap named " << this->_name
					<< " attacks " << this->_attackDamage << " damage"
					<< " and causing it to itself." << std::endl;
	else
		std::cout	<< "ClapTrap named " << this->_name
					<< " attacks " << this->_attackDamage << " damage"
					<< " and causing it to " << target << "." << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout	<< "ClapTrap named " << this->_name
					<< " is destroyed and can't be attacked." << std::endl;
		return ;
	}
	std::cout		<< "ClapTrap named " << this->_name
					<< " is taking " << amount << " damage." << std::endl;
	if (this->_hitPoints <= amount) {
		std::cout	<< "ClapTrap named " << this->_name
					<< " took enough damage and was destroyed." << std::endl;
		this->_hitPoints = 0;
	}
	else
		this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout	<< "ClapTrap named " << this->_name
					<< " can't be repaired, because it's already destroyed."
					<< std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout	<< "ClapTrap named " << this->_name
					<< " can't be repaired, because it has no Energy left."
					<< std::endl;
		return ;
	}
	if(amount == 0)
		std::cout	<< "ClapTrap named " << this->_name
					<< " tries to repair itself for 0 amount of HP,"
					<< " and nothing happens, except he loses 1 Energy."
					<< std::endl;
	else {
		std::cout	<< "ClapTrap named " << this->_name
					<< " repairs itself for " << amount << " HP"
					<< " and loses 1 Energy." << std::endl;
		this->_hitPoints += amount;
	}
	this->_energyPoints--;
}