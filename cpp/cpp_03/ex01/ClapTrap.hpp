#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

protected:

	std::string	_name;
	std::string _target;
	int			_hit_point;
	int			_energy_point;
	int			_attack_point;

public:

	ClapTrap();
	~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap& operator=(const ClapTrap& other);

};

#endif
