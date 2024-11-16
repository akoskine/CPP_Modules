/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:10:54 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/10 15:20:15 by akoskine         ###   ########.fr       */
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
		void	announce( void );
};

#endif