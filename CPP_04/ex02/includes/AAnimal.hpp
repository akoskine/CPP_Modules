/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 04:54:16 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 14:47:23 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <string>

class AAnimal
{
	protected:
		std::string	_type;
		
	public:
		AAnimal();
		AAnimal(const AAnimal& src);
		virtual ~AAnimal();

		AAnimal&	operator=(const AAnimal& src);

		virtual void	makeSound() const = 0;
};

#endif