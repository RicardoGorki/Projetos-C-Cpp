#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "Contructor called" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Destructor called" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void) const
{
	std::cout << _name << " attacks";
	if (_weapon)
		std::cout <<  " with their " << _weapon->getType();
	else
		std::cout << " without";
	std::cout << std::endl;
}
