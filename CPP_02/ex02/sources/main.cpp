/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:57:02 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/15 21:38:18 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "More unary tests" << std::endl;
	std::cout << --a << " (--a)" << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << " (a--)" << std::endl;
	std::cout << a << std::endl;

	Fixed y(5.2f);
	Fixed x(9);
	std::cout << std::endl << "|| Comparision tests ||" << std::endl;
	std::cout << "y = 5.2f\tx = 9" << std::endl;
    std::cout << y << " > " << x << " = " << (y > x ? "true" : "false") << std::endl;
    std::cout << y << " < " << x << " = " << (y < x ? "true" : "false") << std::endl;
    std::cout << y << " >= " << x << " = " << (y >= x ? "true" : "false") << std::endl;
    std::cout << y << " <= " << x << " = " << (y <= x ? "true" : "false") << std::endl;
    std::cout << y << " == " << x << " = " << (y == x ? "true" : "false") << std::endl;
    std::cout << y << " != " << x << " = " << (y != x ? "true" : "false") << std::endl;

	y = 20;
	x = 30;
	std::cout << std::endl << "|| Binary operator tests ||" << std::endl;
	std::cout << "y = 20\t\tx = 30" << std::endl;
    std::cout << y << " + " << x << " = " << (y + x) << std::endl;
    std::cout << y << " - " << x << " = " << (y - x) << std::endl;
    std::cout << y << " * " << x << " = " << (y * x) << std::endl;
    std::cout << y << " / " << x << " = " << (y / x) << std::endl;

	y = 5;
	x = 10;
    std::cout << std::endl << "|| MIN MAX tests ||" << std::endl;
	std::cout << "y = 5\t\tx = 10" << std::endl;
    std::cout << "min(" << y << ", " << x << ") = " << std::min(y, x) << std::endl;
    std::cout << "min(" << x << ", " << y << ") = " << std::min(x, y) << std::endl;
    std::cout << "max(" << y << ", " << x << ") = " << std::max(y, x) << std::endl;
    std::cout << "max(" << x << ", " << y << ") = " << std::max(x, y) << std::endl;

    return 0;
}
