#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << type << " constructor called" << std::endl;
	_newBrain = new Brain;
}

Cat::~Cat()
{
	delete _newBrain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& cpCat) : Animal(cpCat)
{
	type = cpCat.type;
	_newBrain =  new Brain(*cpCat._newBrain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		type = other.type;
		_newBrain = new Brain (*other._newBrain);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
