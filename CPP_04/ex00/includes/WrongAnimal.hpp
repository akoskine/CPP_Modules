/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:23:50 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 00:30:45 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;
		
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& src);
		WrongAnimal(const std::string& type);
		virtual ~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& src);

		const std::string&	getType() const;
		void	makeSound() const;
};

#endif