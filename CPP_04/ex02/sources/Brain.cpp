/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 04:23:53 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 04:40:35 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

/************************* Constructors & Destructors *************************/

Brain::Brain() {
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& src) {
	std::cout << "Brain copy constructor called." << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

/********************************** Operators *********************************/

Brain&	Brain::operator=(const Brain& src) {
	std::cout << "Brain assignment overload operator called." << std::endl;
	for (int i = 0; i < this->nbIdeas; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}

/*********************************** Getters **********************************/

const std::string& Brain::getIdea(int index) const {
	if (index < 0)
		index = 0;
	if (index > this->nbIdeas)
		index = this->nbIdeas;
	return (this->_ideas[index]);
}
/*********************************** Setters **********************************/

void	Brain::setIdea(int index, const std::string& idea) {
	if (index < 0)
		index = 0;
	if (index > this->nbIdeas)
		index = this->nbIdeas;
	this->_ideas[index] = idea;
}
