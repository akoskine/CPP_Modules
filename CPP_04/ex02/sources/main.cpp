/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 02:20:23 by akoskine          #+#    #+#             */
/*   Updated: 2024/01/17 14:48:34 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMAL_NB 6

int main() {
	//AAnimal testAnimal;
	if(ANIMAL_NB % 2 != 0) {
		std::cout << "Number of animals must be even" << std::endl;
		return (1);
	}
	AAnimal	* arrayAnimalObjects[ANIMAL_NB + 1];
	arrayAnimalObjects[ANIMAL_NB] = NULL;

	std::cout	<< std::endl << "Creating array of " << ANIMAL_NB << " animals,"
				<< std::endl << "which contain "
				<< ANIMAL_NB / 2 << " cats and "
				<< ANIMAL_NB - (ANIMAL_NB / 2) << " dogs."
				<< std::endl << std::endl;

	for (int i = 0; i < ANIMAL_NB / 2; i++)
		arrayAnimalObjects[i] = new Cat();
	std::cout << std::endl;
	for (int i = ANIMAL_NB / 2; i < ANIMAL_NB; i++)
		arrayAnimalObjects[i] = new Dog();
	
	std::cout	<< std::endl << "Every animal has something to say:"
				<< std::endl << std::endl;
	for (int i = 0; arrayAnimalObjects[i]; i++)
		arrayAnimalObjects[i]->makeSound();
	
	std::cout	<< std::endl << "Deleting animals" << std::endl << std::endl;
	for (int i = 0; arrayAnimalObjects[i]; i++)
		delete arrayAnimalObjects[i];
	std::cout	<< std::endl;

	std::cout	<< "Let's create 1 cat and 1 dog" << std::endl << std::endl;
	Cat* catOne = new Cat();
	Dog* dogOne = new Dog();

	catOne->getBrain()->setIdea(0, "I am a cat");
	dogOne->getBrain()->setIdea(0, "I am a dog");

	std::cout	<< std::endl;
	std::cout	<< "Idea of catOne: [" << catOne->getBrain()->getIdea(0) << "]" << std::endl;
	std::cout	<< "Idea of dogOne: [" << dogOne->getBrain()->getIdea(0) << "]" << std::endl;
	std::cout	<< std::endl;

	std::cout	<< "Let's create 1 copy of those both animals" << std::endl << std::endl;

	Cat* catTwo = new Cat(*catOne);
	Dog* dogTwo = new Dog(*dogOne);

	std::cout	<< std::endl;
	std::cout	<< "Idea of catTwo: [" << catTwo->getBrain()->getIdea(0) << "]" << std::endl;
	std::cout	<< "Idea of dogTwo: [" << dogTwo->getBrain()->getIdea(0) << "]" << std::endl;
	std::cout	<< std::endl;

	std::cout	<< "Let's put new ideas on original animals" << std::endl << std::endl;

	catOne->getBrain()->setIdea(0, "I am the ORIGINAL cat");
	dogOne->getBrain()->setIdea(0, "I am the ORIGINAL dog");

	std::cout	<< "Idea of catOne: [" << catOne->getBrain()->getIdea(0) << "]" << std::endl;
	std::cout	<< "Idea of dogOne: [" << dogOne->getBrain()->getIdea(0) << "]" << std::endl;
	std::cout	<< "Idea of catTwo: [" << catTwo->getBrain()->getIdea(0) << "]" << std::endl;
	std::cout	<< "Idea of dogTwo: [" << dogTwo->getBrain()->getIdea(0) << "]" << std::endl;

	std::cout	<< std::endl << "Let's make catTwo to catOne and dogTwo to dogOne" << std::endl << std::endl;

	*catTwo = *catOne;
	*dogTwo = *dogOne;

	std::cout	<< std::endl << "What are the ideas of catTwo and dogTwo now?" << std::endl << std::endl;

	std::cout	<< "Idea of catTwo: [" << catTwo->getBrain()->getIdea(0) << "]" << std::endl;
	std::cout	<< "Idea of dogTwo: [" << dogTwo->getBrain()->getIdea(0) << "]" << std::endl;

	std::cout	<< std::endl << "Deleting animals" << std::endl << std::endl;

	delete catOne;
	delete catTwo;
	delete dogOne;
	delete dogTwo;

	return(0);
}