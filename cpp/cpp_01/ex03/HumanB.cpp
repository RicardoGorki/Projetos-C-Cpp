#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
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
	if (_weapon)
		std::cout << _name << " attacks" <<  " with their " << _weapon->getType() << std::endl;
	else
		std::cout << "I don't have a weapon" << std::endl;

}
