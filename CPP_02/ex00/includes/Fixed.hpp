/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:22:42 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/15 16:42:38 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int	_raw;
		static const int	_fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed& src);
		~Fixed();
		Fixed&	operator=(const Fixed& src);
		int	getRawBits( void ) const ;
		void	setRawBits(int const raw);
};

#endif