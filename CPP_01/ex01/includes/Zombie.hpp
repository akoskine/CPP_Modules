/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:10:54 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/10 20:07:22 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class	Zombie
{
	private:
		std::string	_name;
		std::string	_getName();

	public:
		Zombie();
		Zombie(std::string str);
		~Zombie();
		void	zombieName(std::string const name, int i);
		void	announce( void );
};

#endif