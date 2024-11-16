/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:57:21 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/10 21:47:03 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <climits>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <random>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

class Span
{
    private:
        std::vector<int> _range;
        unsigned int _size;
        
    public:
        Span();
        Span(unsigned int N);
        Span(Span const & other);
        Span & operator=(Span const & other);
        ~Span();
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif