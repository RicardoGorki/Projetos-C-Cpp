#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << type << " constructor called" << std::endl; }

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog& cpDog) : Animal(cpDog)
{
	type = cpDog.type;
	std::cout << "Dog copy contructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Dog copy operator called" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "rulf rulf!" << std::endl;
}
