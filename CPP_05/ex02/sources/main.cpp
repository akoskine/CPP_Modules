/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:23:37 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 19:18:15 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{	
	std::cout << YELLOW << "Creating buraucrats..." << RESET << std::endl;
	Bureaucrat bc1("Bureau-Rat", 7);
	Bureaucrat bc2("Bureau-Cat", 147);
	std::cout << YELLOW << bc1 << " created!" << RESET << std::endl;
	std::cout << YELLOW << bc2 << " created!" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Creating forms..." << RESET << std::endl;
	ShrubberyCreationForm	shrubbery("Trees");
	RobotomyRequestForm		robotomy("Vending machine");
	PresidentialPardonForm	presidential("Trainee");
	std::cout << YELLOW << shrubbery << " created!" << RESET << std::endl;
	std::cout << YELLOW << robotomy << " created!" << RESET << std::endl;
	std::cout << YELLOW << presidential << " created!" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << bc2 <<" trying to sign everything..." << RESET << std::endl;
	bc2.signForm(shrubbery);
	bc2.signForm(robotomy);
	bc2.signForm(presidential);
	std::cout << std::endl;

	std::cout << YELLOW << bc1 <<" trying to sign everything..." << RESET << std::endl;
	bc1.signForm(shrubbery);
	bc1.signForm(robotomy);
	bc1.signForm(presidential);
	std::cout << std::endl;

	std::cout << YELLOW << bc1 <<" trying to execute everything..." << RESET << std::endl;
	bc1.executeForm(shrubbery);
	bc1.executeForm(robotomy);
	bc1.executeForm(presidential);
	std::cout << std::endl;

	std::cout << YELLOW << "Incrementing grade of " << bc1 << "..." << RESET << std::endl;
	bc1.increment();
	bc1.increment();
	std::cout << std::endl;

	std::cout << YELLOW << bc1 <<" trying to execute last form..." << RESET << std::endl;
	bc1.executeForm(presidential);
	std::cout << std::endl;
	
	return(0);
}