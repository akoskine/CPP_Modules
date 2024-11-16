/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:10:22 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 03:59:31 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain*	_brain;
		
	public:
		Dog();
		Dog(const Dog& src);
		~Dog();

		Dog&	operator=(const Dog& src);

		Brain*	getBrain() const;
		void	makeSound() const;
};

#endif