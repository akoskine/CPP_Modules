/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:05:20 by akoskine          #+#    #+#             */
/*   Updated: 2024/06/05 18:07:10 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery Creation Form", 145, 137),
	_target("Unknown")
{
	std::cout << CYAN "ShrubberyCreationForm default constructor called." RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	AForm(src),
	_target(src._target)
{
	std::cout << CYAN "ShrubberyCreationForm copy constructor called." RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	AForm("Shrubbery Creation Form", 145, 137),
	_target(target)
{
	std::cout << CYAN "ShrubberyCreationForm attributes constructor called." RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << CYAN "ShrubberyCreationForm destructor called." RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	this->_target = src._target;
	return (*this);
}

std::string const &ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::doExecute() const
{
	std::ofstream file;
	std::string trees =
        "    @@@@@@@@    @@@@@@@@	\n"
        "   @@@@@@@@@@  @@@@@@@@@@	\n"
		"    @@@@@@@@    @@@@@@@@	\n"
		"     @@@@@@      @@@@@@	\n"
		"       ||          ||		\n"
        "       ||          ||		\n"
        "       ||          ||		\n";
	file.open((this->_target + "_shrubbery").c_str());
	if(!file.is_open())
	{
		std::cout << RED << "Failed to open " << (this->_target + "_shrubbery") << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "Trees planted at " << (this->_target + "_shrubbery.") << RESET << std::endl;
	file << trees << std::endl;
	file.close();
}
