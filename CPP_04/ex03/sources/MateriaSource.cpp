/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:32:18 by akoskine          #+#    #+#             */
/*   Updated: 2024/02/06 20:20:19 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	// std::cout << "MateriaSource default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	// std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_templates[i] = NULL;
	*this = src;
}

MateriaSource::~MateriaSource(void) {
	// std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_templates[i] != NULL) {
			delete this->_templates[i];
			this->_templates[i] = NULL;
		}
	}
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & src) {
	// std::cout   << "MateriaSource assignment operator overload called."
    //             << std::endl;
	for (int i = 0; i < 4; i++) {
        if (this->_templates[i] != NULL) {
			delete this->_templates[i];
			this->_templates[i] = NULL;
		}
		if (src._templates[i] != NULL) {
			this->_templates[i] = src._templates[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia) {
	if (!materia) {
		std::cout   << "No materia was given to MateriaSource to learn"
                    << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_templates[i] == NULL) {
			this->_templates[i] = materia;
			std::cout   << "MateriaSource was given " << materia->getType()
			            << " recipe and learned it." << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource is full and cannot learn anymore recipes" << std::endl;
	delete materia;
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (this->_templates[i] && this->_templates[i]->getType() == type) {
			std::cout << "MateriaSource creating " << type << " spell." << std::endl;
			return (this->_templates[i]->clone());
		}
	}
	std::cout	<< "MateriaSource doesn't have \"" << type
				<< "\" recipe learned and can't create it." << std::endl;
	return (NULL);
}

void	MateriaSource::showTemplates() {
	std::cout << "MateriaSource has knowledge of the following recipes:" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << "\t[" << i << "] ";
		if (this->_templates[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_templates[i]->getType() << " spell.";
		std::cout << std::endl;
	}
}
