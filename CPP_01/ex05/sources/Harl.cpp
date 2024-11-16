/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:49:54 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/12 21:36:04 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/************************* Constructors & Destructors *************************/

Harl::Harl() {
}

Harl::~Harl() {
}

/****************************** Private functions *****************************/

void	Harl::debug( void ) {
	std::cout << "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger. "
		"I really do!" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. "
		"You didn’t put enough bacon in my burger! "
		"If you did, I wouldn’t be asking for more!" << std::endl;;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. "
		"I’ve been coming for years whereas you started working here "
		"since last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

/****************************** Public functions ******************************/

void	Harl::complain( std::string level )
{
	typedef void (Harl::*ptr)();
	
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	ptr			messages[4] = {&Harl::debug, &Harl::info,
					&Harl::warning, &Harl::error};
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*messages[i])();
			return ;
		}
	}
	std::cout << "No level to complain" << std::endl;
}