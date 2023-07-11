#include "Cat.hpp"

Cat::Cat()
{
	std::cout << type << "Cat constructor called" << std::endl;
	type = "Cat";
	_newBrain = new Brain;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _newBrain;
}

Cat::Cat(const Cat& other) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = other.type;
	*_newBrain = *other._newBrain;
}

std::string Cat::getIdea(int i)
{
	return (_newBrain->ideas[i]);
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		type = other.type;
		_newBrain = other._newBrain;
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
