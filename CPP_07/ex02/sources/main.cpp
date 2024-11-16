/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:25:12 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/03 13:25:12 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
void printArray(Array<T> array)
{
	std::cout << GREEN << "Array: ";
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i];
	std::cout << RESET << std::endl;
}

int main(void)
{
	std::cout << YELLOW << "[Empty array TEST]" << RESET << std::endl;
	Array<int> emptyArray;
	printArray(emptyArray);
	std::cout << std::endl;

	std::cout << YELLOW << "[Integer array TEST]" << RESET << std::endl;
	Array<int> intArray(4);
	intArray[0] = 1;
	intArray[1] = 2;
	intArray[2] = 3;
	intArray[3] = 4;
	printArray(intArray);
	std::cout << std::endl;

	std::cout << YELLOW << "[Character array TEST]" << RESET << std::endl;
	Array<char> charArray(5);
	charArray[0] = 'H';
	charArray[1] = 'e';
	charArray[2] = 'l';
	charArray[3] = 'l';
	charArray[4] = 'o';
	printArray(charArray);
	std::cout << std::endl;
	
	try
	{
		std::cout << YELLOW << "Accessing an element that is out of bounds ( intArray[5] ) and expecting an exception..." << RESET << std::endl;
		intArray[5] = 10;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
