/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:11:58 by akoskine          #+#    #+#             */
/*   Updated: 2024/08/17 21:11:59 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char**argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong arguments! || Use: ./RPN \"arguments\"" << std::endl;       // vaihda info
        return (1);
    }
    try {
        RPN rpn;

        std::string temp = argv[1];
        for (unsigned long j = 0; j < temp.length(); ++j)
            if (temp[j] != ' ' && temp[j] != '\0') 
            {
                if (isdigit(temp[j]) && isdigit(temp[j + 1]))
                    throw std::out_of_range("Error: Given numbers out of range (0-9)!");
                if (isdigit(temp[j]))
                    rpn.add(temp[j] - '0');
                else
                    rpn.calculate(temp[j]);
            }
        rpn.getTotal();
        
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
