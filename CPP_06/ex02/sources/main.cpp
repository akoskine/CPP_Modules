/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:41:52 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/03 12:41:52 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base    *generate(void)
{
	int	nb = std::rand() % 3;

	if(nb == 0)
    {
			std::cout << "Generated: A";
			return (new A);
    }
	if(nb == 1)
    {
			std::cout << "Generated: B";
			return (new B);
    }
	if(nb == 2)
    {
			std::cout << "Generated: C";
			return (new C);
    }
	return (NULL);
}

void    identify(Base *p)
{
	std::cout << "Identify pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Not specified";
}

void    identify(Base &p)
{
	std::cout << "Identify reference: ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
	}
	catch (std::exception &e) {}
}

int	main()
{
	Base *p;
	std::srand(std::time(NULL));

	for (int i = 0; i < 5; i++)
	{
		std::cout << "RUN [" << i << "] ";
		p = generate();
		std::cout << " | ";
		identify(p);
		std::cout << " | ";
		identify(*p);
		delete (p);
		std::cout << std::endl;
	}
	return (0);
}