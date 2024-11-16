/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:54:57 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/03 12:54:57 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	addFive(int &i);
void	multiplyThree(int &i);
void	capitalizeChar(char &c);

int main()
{
	{
		size_t arraySize = 5;
		int	array[] = {1, 2, 3, 4, 5};
		std::cout << YELLOW << "[(int) addFive TEST]" << std::endl;
		std::cout << "Original array: " << RESET;
		::printArray(array, arraySize);
		::iter(array, arraySize, ::addFive);
		std::cout << YELLOW << "Modified array: " << RESET;
		::printArray(array, arraySize);
	}
	{
		size_t arraySize = 3;
		int	array[] = {2, 4, 6};
		std::cout << YELLOW << "[(int) multiplyThree TEST]" << std::endl;
		std::cout << "Original array: " << RESET;
		::printArray(array, arraySize);
		::iter(array, arraySize, ::multiplyThree);
		std::cout << YELLOW << "Modified array: " << RESET;
		::printArray(array, arraySize);
	}
	{
		size_t arraySize = 4;
		char array[] = {'t', 'e', 's', 't'};
		std::cout << YELLOW << "[(char) capitalizeChar TEST]" << std::endl;
		std::cout << "Original array: " << RESET;
		::printArray(array, arraySize);
		::iter(array, arraySize, ::capitalizeChar);
		std::cout << YELLOW << "Modified array: " << RESET;
		::printArray(array, arraySize);
	}
    
    return(0);
}

void	addFive(int &i)
{
	i += 5;
}

void	multiplyThree(int &i)
{
	i *= 3;
}

void	capitalizeChar(char &c)
{
	c = std::toupper(c);
}