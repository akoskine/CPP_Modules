/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:23:37 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 12:30:52 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	createForm(std::string name, int requiredToSign, int requiredToExecute)
{
	std::cout << "Trying to create form [" << name << ", required to sign/execute: " << requiredToSign << "/" << requiredToExecute << ".]" << std::endl;
	try
	{
		Form form(name, requiredToSign, requiredToExecute);
		std::cout << GREEN << "Form [" << form << "] created successfully." << RESET << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	createAndSign(std::string bcName, int grade, std::string fName, int requiredToSign, int requiredToExecute)
{
	try
	{
		Bureaucrat bureaucrat(bcName, grade);
		Form form(fName, requiredToSign, requiredToExecute);
		
		std::cout << YELLOW << "\"" << bureaucrat << "\" trying to sign \"" << form << "\"" << RESET << std::endl;

		bureaucrat.signForm(form);
	}
	catch(std::exception const &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
int main()
{	
	{
		std::cout << std::endl << YELLOW << "[Default constructor TEST]" << RESET << std::endl;
		Form form;
		std::cout << GREEN << form << " created successfully." << RESET << std::endl;
	}

	{
		std::cout << std::endl << YELLOW << "[Assignment operator overload TEST]" << RESET << std::endl;

		Form form1("Formy-1", 50, 50);
		std::cout << GREEN << form1 << " created successfully." << RESET << std::endl;

		Form form2("Formy-2", 100, 100);
		std::cout << GREEN << form2 << " created successfully." << RESET << std::endl;

		Bureaucrat bureaucrat("Byro-Man", 50);
		std::cout << GREEN << "Bureaucrat [" << bureaucrat << "] created successfully." << RESET << std::endl;

		bureaucrat.signForm(form1);

		std::cout << YELLOW << "Formy-2 = Formy-1" << RESET << std::endl;
		form2 = form1;
		std::cout << YELLOW << form2 << RESET << std::endl;
	}

	{
		std::cout << std::endl << YELLOW << "[Copy constructor TEST]" << RESET << std::endl;
		Form form("TestForm", 50, 50);
		std::cout << GREEN << form << " created successfully." << RESET << std::endl;
		std::cout << YELLOW << "Copying form..." << RESET << std::endl;
		Form copyForm(form);
		std::cout << GREEN << copyForm << " created successfully." << RESET << std::endl;
	}

	{
		std::cout << std::endl << YELLOW << "[Attributes constructor TEST]" << RESET << std::endl;
		createForm("Form1", 170, 170);
		createForm("Form2", -1, -1);
		createForm("Form3", 50, 50);
	}

	{
		std::cout << std::endl << YELLOW << "[Sign TEST]" << RESET << std::endl;

		createAndSign("Bureau-Rat1", 10, "Formy-1", 140, 140);
		createAndSign("Bureau-Rat2", 120, "Formy-1", 140, 140);

		createAndSign("Bureau-Rat1", 10, "Formy-2", 90, 90);
		createAndSign("Bureau-Rat2", 120, "Formy-2", 90, 90);

		createAndSign("Bureau-Rat1", 10, "Formy-3", 5, 5);
		createAndSign("Bureau-Rat2", 120, "Formy-3", 5, 5);
	}

	return(0);
}