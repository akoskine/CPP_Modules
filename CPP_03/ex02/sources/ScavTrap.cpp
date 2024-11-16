/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:28:34 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/16 19:43:21 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

/************************* Constructors & Destructors *************************/

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
}

ScavTrap::ScavTrap(std::string& name): ClapTrap(name) {
	std::cout << "ScavTrap named " << name << " was called" << std::endl;
	this->_hitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap() {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destuctor called" << std::endl;
	std::cout << "ScavTrap named " << this->_name
		<< " was destroyed" << std::endl;
}

/********************************** Operators *********************************/

ScavTrap&	ScavTrap::operator=(const ScavTrap& src) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

/****************************** Public functions ******************************/

void	ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout	<< "ScavTrap named " << this->_name
					<< " can't attack, because it does not have HP."
					<< std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout	<< "ScavTrap named " << this->_name
					<< " can't attack, because it does not have Energy."
					<< std::endl;
		return ;
	}
	if (target == this->_name)
		std::cout	<< "ScavTrap named " << this->_name
					<< " attacks " << this->_attackDamage << " damage"
					<< " and causing it to itself." << std::endl;
	else
		std::cout	<< "ScavTrap named " << this->_name
					<< " attacks " << this->_attackDamage << " damage"
					<< " and causing it to " << target << "." << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate() {
	if (this->_hitPoints == 0) {
		std::cout	<< "ScavTrap named " << this->_name
					<< " can't enter Gate keeper mode, because it"
					<< " does not have HP." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout	<< "ScavTrap named " << this->_name
					<< " can't enter Gate keeper mode, because it"
					<< " does not have Energy." << std::endl;
		return ;
	}
	std::cout		<< "ScavTrap named " << this->_name
					<< " entering Gate keeper mode." << std::endl;
}