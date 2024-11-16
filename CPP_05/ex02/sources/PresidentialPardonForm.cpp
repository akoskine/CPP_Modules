/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:05:20 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 17:47:48 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon Form", 25, 5),
	_target("Unknown")
{
	std::cout << CYAN "PresidentialPardonForm default constructor called." RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	AForm(src),
	_target(src._target)
{
	std::cout << CYAN "PresidentialPardonForm copy constructor called." RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	AForm("Presidential Pardon Form", 25, 5),
	_target(target)
{
	std::cout << CYAN "PresidentialPardonForm attributes constructor called." RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << CYAN "PresidentialPardonForm destructor called." RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	this->_target = src._target;
	return (*this);
}

std::string const &PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::doExecute() const
{
	std::cout << YELLOW << this->_target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
