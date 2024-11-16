/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:10:50 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/15 17:49:07 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_raw;
		static const int	_fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed& src);
		Fixed(const int nValue);
		Fixed(const float fValue);
		~Fixed();
		Fixed&	operator=(const Fixed& src);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& nb);

#endif