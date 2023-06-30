#include "Character.hpp"

Character::Character(){std::cout << "Character constructor called " << std::endl;}

Character::~Character(){std::cout << "Character destructor called " << std::endl;}

Character::Character(const Character& cpCharacter)
{
	std::cout << "Copy Character assignment operator called " << std::endl;
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Copy Character assignment operator called " << std::endl;
	return (*this);
}
