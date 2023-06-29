#include "Animal.hpp"

Animal::Animal() { std::cout << "Animal constructor called" << std::endl; }

Animal::Animal(const Animal& cpAnimal) : type(cpAnimal.type) { std::cout << "Animal copy constructor called" << std::endl; }

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return (*this);
}

void Animal::makeSound() const { std::cout << "Default animal sound" << std::endl; }

std::string Animal::getType() const {	return (this->type); }

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }
