/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:11:08 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/11 19:45:03 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int i;
	int j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				av[i][j] = std::toupper(av[i][j]);
				j++;
			}
			std::cout << av[i];
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}