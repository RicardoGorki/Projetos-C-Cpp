#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

private:

	std::string	_name;
	std::string _target;
	int			_hit_point;
	int			_energy_point;
	int			_attack_point;

public:

	ClapTrap();
	~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &cpClapTrap);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void operator=(const ClapTrap& cp);

};

#endif
