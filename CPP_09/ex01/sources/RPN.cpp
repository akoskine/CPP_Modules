/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:12:10 by akoskine          #+#    #+#             */
/*   Updated: 2024/08/17 21:13:34 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const &copy)
{
    *this = copy;
}
RPN &RPN::operator=(RPN const &copy)
{
    stack = copy.stack;
    return (*this);
}

void    RPN::add(int nb) { stack.push(nb); }

void    RPN::calculate(char op)
{        
    if (stack.empty() || stack.size() < 2)
        throw std::invalid_argument("Error: Invalid amount of numbers given!");
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();
    int temp;
    if (op == '/' && b == 0)
        throw std::invalid_argument("Error: Trying to divide by zero!");
    switch (op)
    {
        case '+':
            temp = a + b;
            stack.push(temp);
            break;
        case '-':
            temp = a - b;
            stack.push(temp);
            break;
        case '*':
            temp = a * b;
            stack.push(temp);
            break;
        case '/':
            temp = a / b;
            stack.push(temp);
            break;
        default:
            throw std::invalid_argument("Error: Invalid operator!");
    }
}

void    RPN::getTotal()
{
    if (stack.empty())
        throw std::invalid_argument("Error: Invalid amount of numbers given!");

    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
    else
        throw std::invalid_argument("Error: Missing required amount of operators!");
}
