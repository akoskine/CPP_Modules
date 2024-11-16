/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:27:18 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/12 19:03:45 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    {
        std::cout << YELLOW << "[SUBJECT TEST - MutantStack]" << RESET << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << GREEN << mstack.top() << RESET << std::endl;
        mstack.pop();
        std::cout << GREEN << mstack.size() << RESET << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << GREEN << *it << RESET << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
        std::cout << std::endl;
    {
        std::cout << YELLOW << "[SUBJECT TEST - list]" << RESET << std::endl;
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << GREEN << mstack.back() << RESET << std::endl;
        mstack.pop_back();
        std::cout << GREEN << mstack.size() << RESET << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << GREEN << *it << RESET << std::endl;
        ++it;
        }
        std::list<int> s(mstack);
    }
        std::cout << std::endl;
    {
        std::cout << YELLOW << "[CHAR TEST]" << RESET << std::endl;
        MutantStack<char> mstack;
        std::cout << YELLOW << "Pushing 'a' 'b' 'c' 'd' 'e' to stack..." << RESET << std::endl;
        for (int i = 0; i < 5; i++)
		    mstack.push('a' + i);
        std::cout << YELLOW << "Printing stack..." << RESET << std::endl;
        for(MutantStack<char>::iterator it = mstack.begin(); it != mstack.end(); it++)
            std::cout << GREEN << "[" << *it << "] ";
        std::cout << RESET << std::endl;
    }

    return (0);
}