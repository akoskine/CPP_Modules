/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:11:22 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/16 20:32:25 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

/************************* Constructors & Destructors *************************/

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
}

FragTrap::FragTrap(std::string& name): ClapTrap(name) {
	std::cout << "FragTrap named " << name << " was called" << std::endl;
	this->_hitPoints = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->_energyPoints = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap() {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destuctor called" << std::endl;
	std::cout << "FragTrap named " << this->_name
		<< " was destroyed" << std::endl;
}

/********************************** Operators *********************************/

FragTrap&	FragTrap::operator=(const FragTrap& src) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

/****************************** Public functions ******************************/

void	FragTrap::highFivesGuys() {
	if (this->_hitPoints == 0)
		std::cout	<< "FragTrap named " << this->_name
					<< " is facedown in mud, but still somehow manages to get"
					<< " its hand up and request highfive." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout	<< "FragTrap named " << this->_name
					<< " is totally out of Energy, but using his secret"
					<< " powersource, it will request highfive." << std::endl;
	else
		std::cout	<< "FragTrap named " << this->_name
					<< " is so thrilled from the battle, that it"
					<< " will request highfive." << std::endl;
	return ;
}