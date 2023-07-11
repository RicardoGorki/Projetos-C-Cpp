#include "Dog.hpp"

Dog::Dog()
{
	std::cout << type << "Dog constructor called" << std::endl;
	type = "Dog";
	_newBrain = new Brain;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _newBrain;
}

Dog::Dog(const Dog& other) : Animal()
{
	std::cout << "Dog copy contructor called" << std::endl;
	type = other.type;
	delete _newBrain;
	_newBrain = new Brain(*other._newBrain);
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		type = other.type;
		delete _newBrain;
		_newBrain = new Brain(*other._newBrain);
	}
	std::cout << "Dog copy operator called" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "rulf rulf!" << std::endl;
}
