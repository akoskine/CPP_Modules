/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:40:18 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/03 12:40:18 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main()
{
    Data        data = {.value = 42, .string = "example"};
	uintptr_t	serializedData = serialize(&data);
	Data        *deserializedData = deserialize(serializedData);

    std::cout << "Original data | Value: " << data.value << " | Str: " << data.string << std::endl;
    std::cout << "deserializedData | Value: " << deserializedData->value << " | Str: " << deserializedData->string << std::endl;

    return (0);
}