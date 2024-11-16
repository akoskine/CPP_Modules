/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:05:20 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 17:47:48 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request Form", 72, 45),
	_target("Unknown")
{
	std::cout << CYAN "RobotomyRequestForm default constructor called." RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	AForm(src),
	_target(src._target)
{
	std::cout << CYAN "RobotomyRequestForm copy constructor called." RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	AForm("Robotomy Request Form", 72, 45),
	_target(target)
{
	std::cout << CYAN "RobotomyRequestForm attributes constructor called." RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << CYAN "RobotomyRequestForm destructor called." RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	this->_target = src._target;
	return (*this);
}

std::string const &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::doExecute() const
{
	std::cout << YELLOW << "** DDRRRZZZ DDRRZZZZ!!! **" << RESET << std::endl;
	if (std::rand() % 2)
		std::cout << YELLOW << this->_target << " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << YELLOW << "Robotomization of " << this->_target << " failed miserably!" << RESET << std::endl;
}