#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Constructor called" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::string const Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(std::string type)
{
	_type = type;
}
