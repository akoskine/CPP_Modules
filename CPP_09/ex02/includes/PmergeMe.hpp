/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:14:28 by akoskine          #+#    #+#             */
/*   Updated: 2024/08/17 21:14:29 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <ctime>

class PmergeMe
{
private:
    std::list<int> _list;
    std::vector<int> _vector;
    PmergeMe();

public:
    ~PmergeMe();
    PmergeMe(PmergeMe const &copy);
    PmergeMe &operator=(PmergeMe const &copy);
    PmergeMe(std::vector<int> &vector, std::list<int> &list);

    void mergeSort(std::list<int> &list);
    void sort(std::list<int> &left, std::list<int> &right, std::list<int> &list);

    void mergeSort(std::vector<int> &vector);
    void sort(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector);

    void print(std::list<int> &list);
    void print(std::vector<int> &vector);
};

#endif