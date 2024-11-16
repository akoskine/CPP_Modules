/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:23:37 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 21:19:30 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	createInternAndForm(std::string name, std::string target)
{
	std::cout << YELLOW << "Trying to create a form named \"" << name
		<< "\" appointed to \"" << target << "\"." << RESET << std::endl;

	Intern	intern;
	Bureaucrat bureaucrat("Bureau-Rat", 3);
	try
	{
		AForm *form = intern.makeForm(name, target);
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete (form);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	createInternAndForm("ShrubberyCreationForm", "Yard");
	createInternAndForm("RobotomyRequestForm", "Bob");
	createInternAndForm("PresidentialPardonForm", "Joe");
	createInternAndForm("iM a FOrM", "jee");
	createInternAndForm("", "");	
	return (0);
}