/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:06:31 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/16 20:09:49 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAGTRAP_DEFAULT_HIT_POINTS 100
# define FRAGTRAP_DEFAULT_ENERGY_POINTS 100
# define FRAGTRAP_DEFAULT_ATTACK_DAMAGE 30

class FragTrap : public ClapTrap
{
	private:
		FragTrap();

	public:
		FragTrap(std::string& name);
		FragTrap(const FragTrap& src);
		~FragTrap();

		FragTrap&	operator=(const FragTrap& src);

		void	highFivesGuys();
};

#endif