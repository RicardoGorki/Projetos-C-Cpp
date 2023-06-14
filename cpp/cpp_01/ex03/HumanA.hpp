#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
private:
	std::string _name;
public:
	HumanA(void);
	~HumanA(void);
	void attack(void);
};

#endif
