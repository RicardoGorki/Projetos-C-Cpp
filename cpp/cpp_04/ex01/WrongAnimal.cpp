#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() { std::cout << "Wrong animal constructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal& cpWrongAnimal) : type(cpWrongAnimal.type) { std::cout << "WrongAnimal copy constructor called" << std::endl; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Wrong animal copy assignment operator called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const { std::cout << "Default wrong animal sound" << std::endl; }

std::string WrongAnimal::getType() const {	return (this->type); }

WrongAnimal::~WrongAnimal() { std::cout << "Wrong animal destructor called" << std::endl; }
