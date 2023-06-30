#include "AMateria.hpp"

AMateria::AMateria() { std::cout << "AMateria constructor called" << std::endl;}

AMateria::~AMateria() { std::cout << "AMateria destructor called" << std::endl;}

AMateria::AMateria (const AMateria& cpAMateria)
{
	type = cpAMateria.type;
	std::cout << "Copy AMateria constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "Copy AMateria assignment operator called " << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}
