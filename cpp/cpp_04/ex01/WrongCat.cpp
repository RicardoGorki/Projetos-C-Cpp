#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	type = "Wrong Cat";
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
