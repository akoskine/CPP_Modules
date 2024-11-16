/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:47:29 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/12 19:05:16 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <algorithm>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

template < typename T, typename C = std::deque<T> > class MutantStack : public std::stack<T, C>
{
	public:
		typedef typename std::stack<T, C>::container_type::iterator iterator;

		MutantStack<T, C>() : std::stack<T, C>() {};
		MutantStack<T, C>(MutantStack<T, C> const & src) : std::stack<T, C>(src) {};
		MutantStack<T, C> &	operator=(MutantStack<T, C> const & src) {
			if (this != &src)
				this->c = src.c;
			return (*this);
		}
        ~MutantStack<T, C>() {};
        
		MutantStack<T, C>::iterator	begin()
        {
			return (this->c.begin());
		}

		MutantStack<T, C>::iterator	end()
        {
			return (this->c.end());
		}
};

#endif