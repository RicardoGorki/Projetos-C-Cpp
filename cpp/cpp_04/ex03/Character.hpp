#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
class Character
{

protected:
	std::string name;
	int slots[4];

public:
	Character();
	~Character();
	Character(const Character& cpCharacter);
	Character& operator=(const Character& other);

};

#endif
