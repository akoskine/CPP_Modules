/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:21:06 by akoskine          #+#    #+#             */
/*   Updated: 2024/07/03 15:03:06 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

template <class T>
class Array
{
private:
	T *array;
	unsigned int lenght;

public:
	Array()
	{
		this->array = NULL;
		this->lenght = 0;
	}

	Array(unsigned int n)
	{
		this->array = new T[n];
		this->lenght = n;
	}

	Array(const Array &src)
	{
		this->array = new T[src.lenght];
		this->lenght = src.lenght;
		for (unsigned int i = 0; i < this->lenght; i++)
				this->array[i] = src.array[i];
	}

	Array &operator=(const Array &rhs)
	{
		delete[] this->array;
		this->array = new T[rhs.size()];
		this->lenght = rhs.size();
		for (unsigned int i = 0; i < rhs.size(); i++)
			this->array[i] = rhs[i];
		return (*this);
	}

	~Array()
	{
		delete[] this->array;
	}

	T &operator[](unsigned int index)
	{
		if (index < this->lenght)
			return (this->array[index]);
		else
			throw std::out_of_range("Index is out of bounds.");
	}

	unsigned int size() const
	{
		return (this->lenght);
	}
};

#endif