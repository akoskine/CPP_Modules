/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:17:39 by akoskine          #+#    #+#             */
/*   Updated: 2024/02/02 14:30:48 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const& src);
		~MateriaSource();

		MateriaSource&	operator=(MateriaSource const& src);

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const& type);
		void		showTemplates();

	private:
		AMateria*	_templates[4];
};

#endif