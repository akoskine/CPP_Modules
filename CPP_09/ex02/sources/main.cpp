/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:14:36 by akoskine          #+#    #+#             */
/*   Updated: 2024/08/17 21:14:37 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        try
        {
            std::list<int> list;
            std::vector<int> vector;
            for (int i = 1; i < argc; ++i)
            {
                if (argv[i] != NULL && *argv[i] != '\0')
                {
                    std::istringstream is(argv[i]);
                    int value;
                    is >> value;
                    if (value < 0)
                        throw std::invalid_argument("Error: arg must be a positive integer");
                    if (is.eof()) {
                        list.push_back(value);
                        vector.push_back(value);
                    }
                }
            }
            PmergeMe algo(vector, list);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}
