/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:39:07 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/16 23:03:07 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>

class Animal
{
	protected:
		std::string	_type;
		
	public:
		Animal();
		Animal(const Animal& src);
		Animal(const std::string& type);
		virtual ~Animal();

		Animal&	operator=(const Animal& src);

		const std::string&	getType() const;
		virtual void	makeSound() const;
};

#endif