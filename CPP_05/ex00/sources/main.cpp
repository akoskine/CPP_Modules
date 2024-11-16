/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:23:37 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/29 12:33:55 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	createBureaucrat(std::string name, int grade)
{
	std::cout << "Trying to create bureaucrat [" << name << ", bureaucrat grade " << grade << ".]" << std::endl;
	try
	{
		Bureaucrat bureaucrat(name, grade);
		std::cout << GREEN << "Bureaucrat [" << bureaucrat << "] created successfully." << RESET << std::endl;
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
		Bureaucrat bureaucrat;
		std::cout << GREEN << "Bureaucrat [" << bureaucrat << "] created successfully." << RESET << std::endl;
	}

	{
		std::cout << std::endl << YELLOW << "[Assignment operator overload TEST]" << RESET << std::endl;
		Bureaucrat bureaucrat1("Jee", 25);
		std::cout << GREEN << "Bureaucrat [" << bureaucrat1 << "] created successfully." << RESET << std::endl;
		Bureaucrat bureaucrat2("Joo", 50);
		std::cout << GREEN << "Bureaucrat [" << bureaucrat2 << "] created successfully." << RESET << std::endl;
		bureaucrat1 = bureaucrat2;
		std::cout << YELLOW << "bureaucrat1 = bureaucrat2" << RESET << std::endl;
		std::cout << YELLOW << "Bureaucrat1 [" << bureaucrat1 << "] assigned succesfully." << RESET << std::endl;
	}

	{
		std::cout << std::endl << YELLOW << "[Copy constructor TEST]" << RESET << std::endl;
		Bureaucrat bureaucrat("TestBureaucrat", 50);
		std::cout << GREEN << bureaucrat << " created successfully." << RESET << std::endl;
		std::cout << YELLOW << "Copying bureaucrat..." << RESET << std::endl;
		Bureaucrat copyBureaucrat(bureaucrat);
		std::cout << GREEN << copyBureaucrat << " created successfully." << RESET << std::endl;
	}

	{
		std::cout << std::endl << YELLOW << "[Attributes constructor TEST]" << RESET << std::endl;
		createBureaucrat("Jee", 170);
		createBureaucrat("Jaa", -1);
		createBureaucrat("Joo", 50);
	}

	{
		std::cout << std::endl << YELLOW << "[Increment/decrement TEST]" << RESET << std::endl;
		{
			Bureaucrat bureaucrat("Test1", 100);
			std::cout << GREEN << "Bureaucrat [" << bureaucrat << "] created successfully." << RESET << std::endl;
			bureaucrat.increment();
			bureaucrat.decrement();
		}

		try
		{
			Bureaucrat bureaucrat("Test2", 150);
			std::cout << GREEN << "Bureaucrat [" << bureaucrat << "] created successfully." << RESET << std::endl;
			bureaucrat.decrement();
		}
		catch(std::exception const &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		
		try
		{
			Bureaucrat bureaucrat("Test3", 1);
			std::cout << GREEN << "Bureaucrat [" << bureaucrat << "] created successfully." << RESET << std::endl;
			bureaucrat.increment();
		}
		catch(std::exception const &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}

	return(0);
}