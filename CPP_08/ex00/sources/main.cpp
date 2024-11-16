/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:03:58 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/03 16:03:58 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> intContainer;

	for (int i = 1; i <= 5; i++) 
        intContainer.push_back(i); 

	try
	{
		std::cout << YELLOW << "Finding value " << GREEN << "1" << YELLOW << std::endl
			<< "Given value " << GREEN << *easyfind(intContainer, 1) << YELLOW
			<< " was found from vector container" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "Finding value " << GREEN << "5" << YELLOW << std::endl
			<< "Given value " << GREEN << *easyfind(intContainer, 5) << YELLOW
			<< " was found from vector container" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "Finding value " << GREEN << "6" << YELLOW << std::endl
			<< "Given value " << GREEN << *easyfind(intContainer, 6) << YELLOW
			<< " was found from vector container" << RESET << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << YELLOW << e.what() << RESET << std::endl;
	}

	return (0);
}