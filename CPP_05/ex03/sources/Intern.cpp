/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:43:31 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 21:17:39 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << CYAN "Intern default constructor called." RESET << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << CYAN "Intern copy constructor called." RESET << std::endl;
	(void)src;
}

Intern::~Intern()
{
	std::cout << CYAN "Intern desctructor called." RESET << std::endl;
}

Intern &Intern::operator=(Intern const &src)
{
	std::cout << CYAN "Intern assignment operator overload called." RESET << std::endl;
	(void)src;
	return (*this);
}

const char *Intern::WrongFormName::what() const throw()
{
	return ("wrong form name.");
}

static AForm *createShrubberyCreationForm(std::string const target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomyRequestForm(std::string const target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createPresidentialPardonForm(std::string const target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string const name, std::string const target)
{
	AForm *(*formFunctions[])(const std::string target)
		= {&createShrubberyCreationForm, &createRobotomyRequestForm, &createPresidentialPardonForm};
	std::string formNames[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << GREEN << "Intern creates form called " << name << "." << RESET << std::endl;
			return (formFunctions[i](target));
		}
	}
	std::cout << RED << "Intern could't create form called \""
		<< name << "\", because of " << RESET;
	throw Intern::WrongFormName();
}