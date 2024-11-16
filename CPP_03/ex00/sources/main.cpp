/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:55:59 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/16 21:12:27 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main() {
	std::string clapNameOne = "FighterOne";
	std::string clapNameTwo = "FighterTwo";

	ClapTrap clap1(clapNameOne);
	ClapTrap clap2(clapNameTwo);

	std::cout	<< "ClapTrap " << clap1.getName() << " atribute check || HP: "
				<< clap1.getHitPoints() << " || Energy: "
				<< clap1.getEnergyPoints() << " || Attack damage: "
				<< clap1.getAttackDamage() << " ||" << std::endl;
	std::cout	<< "ClapTrap " << clap2.getName() << " atribute check || HP: "
				<< clap2.getHitPoints() << " || Energy: "
				<< clap2.getEnergyPoints() << " || Attack damage: "
				<< clap2.getAttackDamage() << " ||" << std::endl;
	clap1.attack(clapNameTwo);
	clap2.takeDamage(0);
	clap2.beRepaired(0);
	clap1.attack(clapNameTwo);
	clap2.takeDamage(0);
	clap2.attack(clapNameOne);
	clap1.takeDamage(0);
	clap1.beRepaired(1);
	clap2.attack(clapNameOne);
	clap1.takeDamage(0);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	clap2.beRepaired(1);
	std::cout << clapNameTwo << " faceplanted to mud and got destroyed." << std::endl;
	clap2.takeDamage(20);
	std::cout << clapNameOne << " tries to stomp " << clapNameTwo
		<< " in ground, but nothing happens because it's already destoyed." << std::endl;
	clap2.takeDamage(5);
	clap2.beRepaired(1);
	std::cout	<< "ClapTrap " << clap2.getName() << " atribute check || HP: "
				<< clap2.getHitPoints() << " || Energy: "
				<< clap2.getEnergyPoints() << " || Attack damage: "
				<< clap2.getAttackDamage() << " ||" << std::endl;
	
	return (0);
}