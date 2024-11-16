/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:54:51 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/03 12:54:51 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

template <typename T, typename F>
void iter(T *array, size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void	printArray(T *array, size_t length)
{
	for (size_t i = 0; i < length; i++)
		std::cout << GREEN << "[" << array[i] << "] ";
	std::cout << RESET << std::endl;
}

#endif