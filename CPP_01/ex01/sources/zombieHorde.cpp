/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:33:54 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/13 17:37:24 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name ) {
	if (N <= 0)
		return (NULL);
	Zombie	*newZombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		newZombieHorde[i].zombieName(name, i);
	return (newZombieHorde);
}