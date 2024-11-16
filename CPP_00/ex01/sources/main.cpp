/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:58:02 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/11 19:45:56 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	PhoneBook phonebook;
	std::string input;

	std::cout << "Welcome to phonebook!" << std::endl;
	while (true)
	{
		std::cout << std::endl
			<< "||--------------- Phonebook ---------------||" << std::endl
			<< "Please use one of the next commands:" << std::endl
			<< "ADD | SEARCH | EXIT" << std::endl
			<< "> ";
		if (!std::getline(std::cin, input) || std::cin.eof()) {
			std::cout << std::endl;
			exit(1);
		}
		if (input == "ADD") {
			if (!phonebook.addContact())
				exit(1);
		}
		else if (input == "SEARCH") {
			if (!phonebook.searchContact())
				exit(1);
		}
		else if (input == "EXIT") {
			std::cout << "Exiting program, thank you!" << std::endl;
			exit(0);
		}
		else
			std::cout << "Command is incorrect. Please try again" << std::endl;
	}
	return(0);
}
