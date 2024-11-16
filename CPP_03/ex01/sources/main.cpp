/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:55:59 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/16 20:58:59 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::string clapName = "FighterOne";
	std::string scavName = "FighterTwo";

	ClapTrap clap(clapName);
	ScavTrap scav(scavName);

	std::cout	<< "ScavTrap " << scav.getName() << " atribute check || HP: "
				<< scav.getHitPoints() << " || Energy: "
				<< scav.getEnergyPoints() << " || Attack damage: "
				<< scav.getAttackDamage() << " ||" << std::endl;
	std::cout	<< "ClapTrap " << clap.getName() << " atribute check || HP: "
				<< clap.getHitPoints() << " || Energy: "
				<< clap.getEnergyPoints() << " || Attack damage: "
				<< clap.getAttackDamage() << " ||" << std::endl;
	scav.attack(clapName);
	clap.takeDamage(SCAVTRAP_DEFAULT_ATTACK_DAMAGE);
	std::cout	<< "ClapTrap " << clap.getName() << " atribute check || HP: "
				<< clap.getHitPoints() << " || Energy: "
				<< clap.getEnergyPoints() << " || Attack damage: "
				<< clap.getAttackDamage() << " ||" << std::endl;
	clap.beRepaired(1);
	std::cout << scavName << " tries to hit " << clapName << " even it's already smashed to the ground." << std::endl;
	clap.takeDamage(SCAVTRAP_DEFAULT_ATTACK_DAMAGE);
	scav.guardGate();
	std::cout << scavName << " is guarding the gate, but slips over!" << std::endl;
	scav.takeDamage(150);
	scav.beRepaired(100);
	std::cout	<< "ScavTrap " << scav.getName() << " atribute check || HP: "
				<< scav.getHitPoints() << " || Energy: "
				<< scav.getEnergyPoints() << " || Attack damage: "
				<< scav.getAttackDamage() << " ||" << std::endl;
	
	return (0);
}