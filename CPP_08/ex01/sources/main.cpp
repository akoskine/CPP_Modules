/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:54:38 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/03 12:54:38 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int myRandomize(int smallest, int highest)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(smallest, highest);
    return distribution(generator);
}

int main()
{
	{
		try
		{
		std::cout << YELLOW << "[subject TEST]" << RESET << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << sp.longestSpan() << RESET << std::endl;	
		}
		catch(std::exception & e)
		{
			std::cerr << RED << "Error exception: " << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;
	}

	{
		try
		{
		std::cout << YELLOW << "[addNumber TEST]" << RESET << std::endl;

		std::cout << YELLOW << "adding 5 numbers & showing results..." << RESET << std::endl;
		Span sp = Span(5);

		sp.addNumber(1);
		sp.addNumber(5);
		sp.addNumber(8);
		sp.addNumber(12);
		sp.addNumber(20);

		std::cout << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << sp.longestSpan() << RESET << std::endl;

		std::cout << YELLOW << "trying add more with addNumber -function..." << RESET << std::endl;

		sp.addNumber(25);
		}
		catch(std::exception & e)
		{
			std::cerr << RED << "Error exception: " << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;	
	}

	{
		try
		{
		std::cout << YELLOW << "[addRange TEST]" << RESET << std::endl;

		std::cout << YELLOW << "adding 10000 numbers & showing results..." << RESET << std::endl;

		Span sp = Span(10000);
		std::vector<int> rangeContainer;
		for(int i = 0; i < 10000;)
		{
			int j = myRandomize(-50000, 50000);
			if (std::find(rangeContainer.begin(), rangeContainer.end(), j) == rangeContainer.end())
			{
			    rangeContainer.push_back(j);
				i++;
			}
		}
		sp.addRange(rangeContainer.begin(), rangeContainer.end());

		std::cout << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << sp.longestSpan() << RESET << std::endl;
		std::cout << YELLOW << "trying add more with addRange -function..." << RESET << std::endl;

		sp.addRange(rangeContainer.begin(), rangeContainer.end());
		}
		catch(std::exception & e)
		{
			std::cerr << RED << "Error exception: " << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;	
	}
	
    return(0);
}