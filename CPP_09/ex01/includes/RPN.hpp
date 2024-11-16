/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:11:34 by akoskine          #+#    #+#             */
/*   Updated: 2024/08/17 21:13:07 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
    private:
        std::stack<int> stack;
    public:
        RPN();
        ~RPN();
        RPN(RPN const &copy);
        RPN &operator=(RPN const &copy);

        void    add(int nb);
        void    calculate(char op);
        void    getTotal();
};

#endif