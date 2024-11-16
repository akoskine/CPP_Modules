/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 01:22:17 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 01:37:29 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "||\tMandatory subject tests\t||" << std::endl;
	{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	std::cout << std::endl;
	}
	std::cout << std::endl << "||\tAnimal class tests\t||" << std::endl;
	{
		std::cout << "Animal by animal class" << std::endl;
		const Animal *	animal = new Animal();
		std::cout << "Animal type: " << animal->getType() << std::endl;
		animal->makeSound();
		delete animal;
		std::cout << std::endl;
	}
	{
		std::cout << "Cat by animal class" << std::endl;
		const Animal * cat = new Cat();
		std::cout << "Animal type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
		std::cout << std::endl;
	}
	{
		std::cout << "Dog by animal class" << std::endl;
		const Animal * dog = new Dog();
		std::cout << "Animal type: " << dog->getType() << std::endl;
		dog->makeSound();
		delete dog;
		std::cout << std::endl;
	}
	std::cout << std::endl << "||\tCat & Dog class tests\t||" << std::endl;
	{
		std::cout << "Cat by cat class" << std::endl;
		const Cat *	cat = new Cat();
		std::cout << "Cat type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
		std::cout << std::endl;
	}
	{
		std::cout << "Dog by dog class" << std::endl;
		const Dog *	dog = new Dog();
		std::cout << "Dog type: " << dog->getType() << std::endl;
		dog->makeSound();
		delete dog;
		std::cout << std::endl;
	}
	std::cout << std::endl << "||\tWrongAnimal class tests\t||" << std::endl;
	{
		std::cout << "WrongAnimal by WrongAnimal class" << std::endl;
		const WrongAnimal *	animal = new WrongAnimal();
		std::cout << "WrongAnimal type: " << animal->getType() << std::endl;
		animal->makeSound();
		delete animal;
		std::cout << std::endl;
	}
	{
		std::cout << "WrongCat by WrongAnimal class" << std::endl;
		const WrongAnimal * cat = new WrongCat();
		std::cout << "WrongAnimal type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
		std::cout << std::endl;
	}
	std::cout << std::endl << "||\tWrongCat class tests\t||" << std::endl;
	{
		std::cout << "WrongCat by WrongCat class" << std::endl;
		const WrongCat *	cat = new WrongCat();
		std::cout << "WrongCat type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
		std::cout << std::endl;
	}
	return (0);
}