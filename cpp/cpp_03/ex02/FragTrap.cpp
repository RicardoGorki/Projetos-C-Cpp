#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;
	_name = "FragTrap_Anonimous";
	_hit_point = 100;
	_energy_point = 100;
	_attack_point = 30;
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

FragTrap::FragTrap(const FragTrap &other) : ClapTrap()
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	_name = other._name;
	_hit_point = other._hit_point;
	_energy_point = other._energy_point;
	_attack_point = other._attack_point;
};

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	_name = other._name;
	_hit_point = other._hit_point;
	_energy_point = other._energy_point;
	_attack_point = other._attack_point;
	return (*this);
};

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_name = name;
	_hit_point = 100;
	_energy_point = 100;
	_attack_point = 30;
}

void FragTrap::highFivesGuys(void)
{
	if (_hit_point > 0)
	{
 		std::cout << _name << " positive high fives request!" << std::endl;
	}
}
