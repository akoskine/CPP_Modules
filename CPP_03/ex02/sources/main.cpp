/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:55:59 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/16 21:02:10 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::string clapName = "FighterOne";
	std::string fragName = "FighterTwo";

	ClapTrap clap(clapName);
	FragTrap frag(fragName);

	std::cout	<< "FragTrap " << frag.getName() << " atribute check || HP: "
				<< frag.getHitPoints() << " || Energy: "
				<< frag.getEnergyPoints() << " || Attack damage: "
				<< frag.getAttackDamage() << " ||" << std::endl;
	std::cout	<< "ClapTrap " << clap.getName() << " atribute check || HP: "
				<< clap.getHitPoints() << " || Energy: "
				<< clap.getEnergyPoints() << " || Attack damage: "
				<< clap.getAttackDamage() << " ||" << std::endl;
	frag.attack(clapName);
	clap.takeDamage(FRAGTRAP_DEFAULT_ATTACK_DAMAGE);
	std::cout	<< "ClapTrap " << clap.getName() << " atribute check || HP: "
				<< clap.getHitPoints() << " || Energy: "
				<< clap.getEnergyPoints() << " || Attack damage: "
				<< clap.getAttackDamage() << " ||" << std::endl;
	clap.beRepaired(1);
	std::cout << fragName << " tries to hit " << clapName << " even it's already smashed to the ground." << std::endl;
	clap.takeDamage(FRAGTRAP_DEFAULT_ATTACK_DAMAGE);
	frag.highFivesGuys();
	std::cout << fragName << " is just about to highfive and gets hit by a meteor!" << std::endl;
	frag.takeDamage(150);
	frag.highFivesGuys();
	frag.beRepaired(100);
	std::cout	<< "FragTrap " << frag.getName() << " atribute check || HP: "
				<< frag.getHitPoints() << " || Energy: "
				<< frag.getEnergyPoints() << " || Attack damage: "
				<< frag.getAttackDamage() << " ||" << std::endl;
	return (0);
}