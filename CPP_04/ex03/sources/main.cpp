/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:32:12 by akoskine          #+#    #+#             */
/*   Updated: 2024/02/06 20:36:10 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	subjectTests() {
	std::cout << std::endl << std::endl << "\t|| Subject Tests ||" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
    me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	materiaSourceTests() {
	std::cout << std::endl << std::endl << "\t|| MateriaSource Tests ||" << std::endl;
	std::cout << std::endl << "-> creating MateriaSource..." << std::endl;
	MateriaSource *src = new MateriaSource();
	src->showTemplates();

	std::cout << std::endl << "-> creating empty materia..." << std::endl;
	src->learnMateria(NULL);

	std::cout << std::endl << "-> creating 2 different materias..." << std::endl;
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->showTemplates();

	std::cout << std::endl << "-> deep copying MateriaSource..." << std::endl;
	MateriaSource *srcCopy = new MateriaSource(*src);
	std::cout << "Original ";
	src->showTemplates();
	std::cout << "Copy ";
	srcCopy->showTemplates();

	std::cout << std::endl << "-> adding new materia to original MateriaSource..." << std::endl;
	src->learnMateria(new Cure());
	std::cout << "Original ";
	src->showTemplates();
	std::cout << "Copy ";
	srcCopy->showTemplates();

	std::cout << std::endl << "-> deleting copy MateriaSource..." << std::endl;
	delete srcCopy;

	std::cout << std::endl << "-> adding too many materias to MateriaSource..." << std::endl;
	src->showTemplates();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl << "-> creating new AMaterias from MateriaSource..." << std::endl;
	AMateria *	m1 = NULL;
	AMateria *	m2 = NULL;
	AMateria *	m3 = NULL;

	m1 = src->createMateria("ice");
	if (m1 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m1->getType() << std::endl;
	m2 = src->createMateria("cure");
	if (m2 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
		std::cout << "Created materia is " << m2->getType() << std::endl;
	m3 = src->createMateria("randomSpell");
	if (m3 == NULL)
		std::cout << "Materia was not created." << std::endl;
	else
	std::cout << "Created materia is " << m3->getType() << std::endl;

	std::cout << std::endl << "-> deleting AMaterias..." << std::endl;
	if (m1 != NULL)
		delete m1;
	if (m2 != NULL)
		delete m2;
	if (m3 != NULL)
		delete m3;
	std::cout << std::endl << "-> deleting MateriaSource..." << std::endl;
	delete src;
}

void	characterTests() {
	std::cout << std::endl << std::endl << "\t|| Character Tests ||" << std::endl;
	std::cout << std::endl << "-> creating new AMaterias..." << std::endl;
	AMateria *m1 = new Cure();
	AMateria *m2 = new Ice();
	AMateria *m3 = new Cure();
	AMateria *m4 = new Ice();
	AMateria *m5 = new Cure();

	std::cout << std::endl << "-> creating new Character..." << std::endl;
	Character *bob = new Character("bob");
	bob->showInventory();

	std::cout << std::endl << "-> equipping empty AMateria..." << std::endl;
	bob->equip(NULL);

	std::cout << std::endl << "-> equipping valid AMaterias..." << std::endl;
	bob->equip(m1);
	bob->equip(m2);
	bob->showInventory();

	std::cout << std::endl << "-> deepcopying Character bob and changing copys name..." << std::endl;
	Character *bobCopy = new Character(*bob);
	bobCopy->setName("bobCopy");
	bob->showInventory();
	bobCopy->showInventory();

	std::cout << std::endl << "-> adding new AMateria to original bobs inventory..." << std::endl;
	bob->equip(m3);
	bob->showInventory();
	bobCopy->showInventory();

	std::cout << std::endl << "-> deleting Character bobCopy..." << std::endl;
	delete bobCopy;

	std::cout << std::endl << "-> adding too many items to bobs inventory..." << std::endl;
	bob->equip(m4);
	bob->equip(m5);

	std::cout << std::endl << "-> unequipping items from bobs inventory and equipping them again..." << std::endl;
	bob->unequip(-1);
	bob->unequip(5);
	bob->unequip(3);
	bob->unequip(3);
	bob->unequip(2);
	bob->unequip(1);
	bob->unequip(0);
	bob->showInventory();

	std::cout << std::endl << "-> deleting Character bob..." << std::endl;
	delete bob;
	
	std::cout << std::endl << "-> deleting unequipped AMateria..." << std::endl;
		if (m1 != NULL)
			delete m1;
		if (m2 != NULL)
			delete m2;
		if (m3 != NULL)
			delete m3;
		if (m4 != NULL)
			delete m4;
		if (m5 != NULL)
			delete m5;
}

void	fightTests() {
	std::cout << std::endl << std::endl << "\t|| Fight Tests ||" << std::endl;
	std::cout << std::endl << "-> creating MateriaSource..." << std::endl;
	MateriaSource *src = new MateriaSource();
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	std::cout << std::endl << "-> creating stack of 4 materias from MateriaSource..." << std::endl;
	AMateria *stack[5];
	stack[4] = NULL;
	for (int i = 0; i < 4; i++) {
		if (i % 2)
			stack[i] = src->createMateria("ice");
		else
			stack[i] = src->createMateria("cure");
	}

	std::cout << std::endl << "-> creating Characters..." << std::endl;
	Character *bob = new Character("bob");
	Character *pete = new Character("pete");

	std::cout << std::endl << "-> equipping Characters..." << std::endl;
	for (int i = 0; i < 2; i++)
		bob->equip(stack[i]);
	for (int i = 2; i < 4; i++)
		pete->equip(stack[i]);
	bob->showInventory();
	pete->showInventory();

	std::cout << std::endl << "-> fighting starts..." << std::endl;
	bob->use(-1, *bob);
	bob->use(2, *bob);
	bob->use(1, *pete);
	bob->use(0, *pete);
	pete->use(5, *pete);
	pete->use(2, *pete);
	pete->use(1, *bob);
	pete->use(0, *bob);
	bob->use(1, *pete);
	pete->use(0, *pete);
	pete->use(1, *bob);
	bob->use(0, *bob);
	std::cout << "-> fighting stops..." << std::endl;

	std::cout << std::endl << "-> deleting Characters..." << std::endl;
	delete bob;
	delete pete;

	std::cout << std::endl << "-> deleting MateriaSource..." << std::endl;
	delete src;
}

int	main(void)
{
	subjectTests();
	materiaSourceTests();
	characterTests();
	fightTests();
	return (0);
}
