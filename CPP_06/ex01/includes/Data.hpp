/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:39:51 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/03 12:39:51 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
	unsigned int	value;
	std::string		string;
};

uintptr_t	serialize(Data * ptr);
Data        *deserialize(uintptr_t raw);

#endif