#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{

protected:

	std::string type;

public:

	Animal();
	virtual ~Animal();
	Animal(const Animal& cpAnimal);
	Animal& operator=(const Animal& other);
	std::string getType() const;
	virtual void makeSound() const = 0;

};

#endif
