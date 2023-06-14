#include "Weapon.hpp"

Weapon::Weapon(void)
{
	std::cout << "Constructor called" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::string Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(std::string type)
{
	_type = type;
}
