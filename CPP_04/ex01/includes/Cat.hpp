/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:01 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 03:59:24 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(const Cat& src);
		~Cat();

		Cat&	operator=(const Cat& src);

		Brain*	getBrain() const;
		void	makeSound() const;
};

#endif