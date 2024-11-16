/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:15:57 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/12 21:52:03 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	const	str = "HI THIS IS BRAIN";
	std::string	const	*stringPTR = &str;
	std::string	const	&stringREF = str;

	std::cout << "|| MEMORY ADDRESS ||" << std::endl
		<< "String:\t\t" << &str << std::endl
		<< "StringPTR:\t" << stringPTR << std::endl
		<< "StringREF:\t" << &stringREF << std::endl << std::endl;
	std::cout << "|| VALUES ||" << std::endl
		<< "Value of string:\t" << str << std::endl
		<< "Value of stringPTR:\t" << *stringPTR << std::endl
		<< "Value of stringREF:\t" << stringREF << std::endl;
	return (0);
}