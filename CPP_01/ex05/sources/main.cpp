/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:25:23 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/12 21:36:07 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("INFO");
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("WARNING");
	harl.complain("WARNING");
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("ERROR");
	harl.complain("ERROR");
	harl.complain("ERROR");
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("no complain");
	std::cout << std::endl;
	return (0);
}