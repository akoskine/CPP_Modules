/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:19:26 by akoskine          #+#    #+#             */
/*   Updated: 2024/05/31 17:20:16 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
	(void)src;
	return *this;
}

void ScalarConverter::doConvertion(std::string const & input)
{
	std::string str = input;

	int			valueType = 0;
	long int	intValue;
	float		floatValue;
	double		doubleValue;
	std::string tmp;
	std::string	specials[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for(int i = 0; i < 6; i++)
	{
		if(specials[i] == str)
		{
			if(i < 3)
				tmp = str.substr(0,str.size() - 1);
			else
				tmp = str.substr();
		std::cout << YELLOW << "converting \"" << str << "\"..." << RESET << std::endl;
		std::cout << GREEN << "char: " << "impossible" << RESET << std::endl;
		std::cout << GREEN << "int: " << "impossible" << RESET << std::endl;
		std::cout << GREEN << "float: " << tmp << "f" << RESET << std::endl;
		std::cout << GREEN << "double: " << tmp << RESET << std::endl;
		exit(0);
		}
	}
	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		std::cout << YELLOW << "converting \"" << str << "\"..." << RESET << std::endl;
		std::cout << GREEN << "char: '" << str << "'" << RESET << std::endl;
		std::cout << GREEN << "int: " << static_cast<int>(str[0]) << RESET << std::endl;
		std::cout << GREEN << "float: " << static_cast<float>(str[0]) << ".0f" << RESET << std::endl;
		std::cout << GREEN << "double: " << static_cast<double>(str[0]) << ".0" << RESET << std::endl;
		exit(0);
	}
	size_t periodPos = -1;
	if(str[str.size() - 1] == 'f')
	{
		tmp = str.substr(0,str.size() - 1);
		valueType = 3;
	}
	else
		tmp = str.substr();
	for(int i = 0; tmp[i] != '\0'; i++)
	{
		if(i == 0 && tmp[i] == '-')
		{
			if(tmp[1] == '.' && tmp.size() == 2)
			{
				std::cout << RED << "Invalid input!" << RESET << std::endl;
				exit(0);
			}
			i = 1;
		}
		if(!std::isdigit(tmp[i]))
		{
			if(tmp[i] == '.' && periodPos == std::string::npos)
			{
				if(!valueType)
					valueType = 4;
				periodPos = i;
			}
			else
			{
				std::cout << RED << "Invalid input!" << RESET << std::endl;
				exit(0);
			}
		}
	}
	if(!valueType)
	{
		if(tmp.size() <= 11)
		{
			intValue = std::atoi(tmp.c_str());
			if(intValue > INT_MAX || intValue < INT_MIN)
			{
				std::cout << RED << "Invalid input!" << RESET << std::endl;
				exit(0);
			}
			else
				valueType = 2;
		}
		else
		{
			std::cout << RED << "Invalid input!" << RESET << std::endl;
			exit(0);
		}
	}
	std::cout << YELLOW << "converting \"" << str << "\"..." << RESET << std::endl;
	if(valueType > 2)
	{
		if(periodPos >= 0 && periodPos <= 12)
		{
			intValue = std::atoi(tmp.c_str());
			if(intValue <= INT_MAX && intValue >= INT_MIN)
			{
				if(intValue >= 32 && intValue <= 126)
					std::cout << GREEN << "char: '" << static_cast<char>(intValue) << "'" << RESET << std::endl;
				else
					std::cout << GREEN << "char: impossible" << RESET << std::endl;
				std::cout << GREEN << "int: " << static_cast<int>(intValue) << RESET << std::endl;
			}
			else
			{
				std::cout << GREEN << "char: impossible" << RESET << std::endl;
				std::cout << GREEN << "int: impossible" << RESET << std::endl;
			}
		}
		else
		{
			std::cout << GREEN << "char: impossible" << RESET << std::endl;
			std::cout << GREEN << "int: impossible" << RESET << std::endl;
		}
		if(valueType == 3)
		{
			floatValue = std::atof(tmp.c_str());
			doubleValue = static_cast<double>(floatValue);
		}
		else
		{
			doubleValue = std::atof(tmp.c_str());
			floatValue = static_cast<float>(doubleValue);
		}
	}
	else
	{
		floatValue = static_cast<float>(intValue);
		doubleValue = static_cast<double>(intValue);
		if(intValue >= 32 && intValue <= 126)
			std::cout << GREEN << "char: '" << static_cast<char>(intValue) << "'" << RESET << std::endl;
		else
			std::cout << GREEN << "char: impossible" << RESET << std::endl;
		std::cout << GREEN << "int: " << static_cast<int>(intValue) << RESET << std::endl;
	}
	std::cout << GREEN << "float: " << floatValue << ".0f" << RESET << std::endl;
	std::cout << GREEN << "double: " << doubleValue << ".0" << RESET << std::endl;
}