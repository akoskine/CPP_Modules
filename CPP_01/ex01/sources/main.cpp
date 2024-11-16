/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:37:19 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/13 17:36:06 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	zombiesAmount() {
	int nb;

	std::cout << "Please provide amount of zombies (1 - 25)" << std::endl << "> ";
	while (!(std::cin >> nb) || nb > 25 || nb < 1) {
		if (std::cin.eof())
			return (0);
		std::cout << "Try number between 1 - 25" << std::endl << "> ";
	}
	return (nb);
}

int main() {
	int nb;
	std::string name;

	nb = zombiesAmount();
	Zombie *horde = zombieHorde(nb, "Zombie_");
	if (horde == NULL) {
		std::cout << "Allocation failed!" << std::endl;
		return (1);
	}
	for (int i = 0; i < nb; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}