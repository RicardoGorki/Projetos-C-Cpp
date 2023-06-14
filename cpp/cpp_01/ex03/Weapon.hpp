#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{

private:

	std::string _type;

public:

	Weapon(void);
	~Weapon(void);
	std::string getType() const;
	void setType(std::string type);

};

#endif
