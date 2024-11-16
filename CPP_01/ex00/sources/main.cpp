/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:21:52 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/10 16:56:14 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

int main() {
	Zombie *z = newZombie("zombiii");
	z->announce();
	randomChump("rChump");
	delete z;
	return (0);
}