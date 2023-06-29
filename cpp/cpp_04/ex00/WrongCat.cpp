#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "Wrong Cat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat& cpWrongCat)
{
	type = cpWrongCat.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
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
