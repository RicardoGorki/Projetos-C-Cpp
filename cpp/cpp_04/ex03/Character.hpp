#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character
{
public:
	Character();
	~Character();
	Character(const Character& cpCharacter);
	Character& operator=(const Character& other);

};

#endif
