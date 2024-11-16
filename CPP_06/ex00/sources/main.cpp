/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:12:43 by akoskine          #+#    #+#             */
/*   Updated: 2024/06/05 20:59:29 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cout << "Wrong amount of arguments!" << std::endl;
		exit(1);
	}

	ScalarConverter::doConvertion(av[1]);

	return (0);
}