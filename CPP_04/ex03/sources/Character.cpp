/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:59:42 by akoskine          #+#    #+#             */
/*   Updated: 2024/02/06 20:19:28 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Character.hpp"

Character::Character() : _name("Unnamed") {
	// std::cout << "Character default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const& src) {
	// std::cout << "Character copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = src;
}

Character::Character(std::string const& name) : _name(name) {
	// std::cout << "Character name constructor called with name \""
	// 	<< this->_name << "\"." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character() {
	// std::cout << "Character destructor called for \"" << this->_name << "\"." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

Character&	Character::operator=(Character const& src) {
	// std::cout << "Character assignment operator overload called." << std::endl;
	_name = src._name;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
		if (src._inventory[i] != NULL)
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return (*this);
}

std::string const &	Character::getName() const {
	return (this->_name);
}

void	Character::setName(std::string const& newName) {
	this->_name = newName;
}

void	Character::equip(AMateria* materia) {
	if (!materia) {
		std::cout << this->_name << ": Can't equip spell because it doesn't exist!"
			<< std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			std::cout << this->_name
				<< " equipped " << materia->getType()
				<< " spell to inventory index " << i << "." << std::endl;
			return ;
		}
	}
	std::cout << this->_name << ": Inventory full, can't equip anymore spells!" << std::endl;
}

void	Character::unequip(int index) {
	if (index < 0 || index >= 4)
	{
		std::cout << this->_name << ": Cannot unequip anything from inventory index "
		<< index << ", because it's not a valid index!" << std::endl;
		return ;
	}
	if (this->_inventory[index] == NULL)
	{
		std::cout << this->_name << ": Index "
		<< index << " is empty and cannot be unequipped!" << std::endl;
		return ;
	}
	std::cout << this->_name << " unequipped " << this->_inventory[index]->getType()
		<< " spell from inventory index " << index << "." << std::endl;
	this->_inventory[index] = NULL;	
}

void	Character::use(int index, ICharacter& target) {
	if (index < 0 || index >= 4)
	{
		std::cout << this->_name << ": Cannot use spell from inventory index "
		<< index << ", because it's not a valid index!" << std::endl; 
		return ;
	}
	if (this->_inventory[index] != NULL)
	{
		std::cout << this->_name << ": ";
		this->_inventory[index]->use(target);
	}
	else
		std::cout << this->_name
			<< ": No spell equipped at index "
			<< index << "!" << std::endl;
}

void	Character::showInventory() const {
	std::cout << this->_name << "'s inventory contains:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\t[" << i << "] ";
		if (this->_inventory[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_inventory[i]->getType() << " spell.";
		std::cout << std::endl;
	}
}
