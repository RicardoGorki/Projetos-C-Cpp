#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	_newBrain = new Brain;
	std::cout << type << " constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _newBrain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& cpDog) : Animal(cpDog)
{
	type = cpDog.type;
	*_newBrain = *cpDog._newBrain;
	std::cout << "Dog copy contructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		type = other.type;
		_newBrain = other._newBrain;
	}
	std::cout << "Dog copy operator called" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "rulf rulf!" << std::endl;
}
