/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:24:24 by akoskine          #+#    #+#             */
/*   Updated: 2024/02/06 20:51:53 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(Character const& src);
		Character(std::string const& name);
		~Character();

		Character&	operator=(Character const& src);

		std::string const &	getName() const;
		void				setName(std::string const& newName);
		void				equip(AMateria* m);
		void				unequip(int	idx);
		void				use(int idx, ICharacter& target);
		void				showInventory() const;

	private:
		std::string	_name;
		AMateria*	_inventory[4];
};

#endif