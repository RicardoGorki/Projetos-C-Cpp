#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
class Character
{
public:
	Character();
	~Character();
	Character(const Character& cpCharacter);
	Character& operator=(const Character& other);

};

#endif
