#include "Cat.hpp"

Cat::Cat()
{
	std::cout << type << "Cat constructor called" << std::endl;
	type = "Cat";
	_newBrain = new Brain();
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
	delete _newBrain;
	_newBrain = new Brain(*other._newBrain);
}


Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		type = other.type;
		delete _newBrain;
		_newBrain = new Brain(*other._newBrain);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string Cat::getIdea(int i)
{
	if (i >= 0 && i < 100)
    	return (_newBrain->ideas[i]);
	return "";
}

void Cat::setIdea(const std::string& idea, int i)
{
	if (i >= 0 && i < 100)
		_newBrain->ideas[i] = idea;
}
