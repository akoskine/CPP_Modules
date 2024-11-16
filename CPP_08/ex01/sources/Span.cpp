/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:00:18 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/10 21:51:25 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N)
{
    this->_size = N;
}

Span::Span(Span const & other)
{
    *this = other;
}

Span & Span::operator=(Span const & other)
{
    this->_range = other._range;
    this->_size = other._size;
    return(*this);
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (this->_range.size() == this->_size)
		throw std::out_of_range("Maximum amount of numbers reached!");
	this->_range.push_back(number);
}

int Span::shortestSpan()
{
    if (this->_range.size() <= 1)
        throw std::out_of_range("Vector too small!");
    int minDifference = INT_MAX;
    std::vector<int> sortedRange = this->_range;
    std::sort(sortedRange.begin(), sortedRange.end());
    for (size_t i = 1; i < sortedRange.size(); ++i)
    {
        int difference = std::abs(sortedRange[i] - sortedRange[i - 1]);
        minDifference = std::min(minDifference, difference);
    }
    return minDifference;
}

int Span::longestSpan()
{
    if (this->_range.size() <= 1)
		throw std::out_of_range("Vector too small!");
	int	minValue = *std::min_element(this->_range.begin(), this->_range.end());
	int maxValue = *std::max_element(this->_range.begin(), this->_range.end());
	return (abs(maxValue - minValue));
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    unsigned int distance = std::distance(begin, end);

    if (distance > (this->_size - this->_range.size()))
        throw std::out_of_range("Maximum amount of numbers reached!");
    if (distance != 0)
        this->_range.insert(this->_range.end(), begin, end);
}
