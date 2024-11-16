/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:55:36 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/16 19:25:40 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAVTRAP_DEFAULT_HIT_POINTS 100
# define SCAVTRAP_DEFAULT_ENERGY_POINTS 50
# define SCAVTRAP_DEFAULT_ATTACK_DAMAGE 20

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap();

	public:
		ScavTrap(std::string& name);
		ScavTrap(const ScavTrap& src);
		~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& src);

		void		attack(const std::string& target);
		void		guardGate();
};

#endif