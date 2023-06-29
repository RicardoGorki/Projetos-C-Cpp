#include "ClapTrap.hpp"

ClapTrap::ClapTrap() { std::cout << "Constructor called" << std::endl;}


ClapTrap::ClapTrap(std::string name) : _name(name), _hit_point(10), _energy_point (10), _attack_point(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap &cpClapTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = cpClapTrap._name;
	_hit_point = cpClapTrap._hit_point;
	_energy_point = cpClapTrap._energy_point;
	_attack_point = cpClapTrap._attack_point;
};

void ClapTrap::operator=(const ClapTrap& cp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_name = cp._name;
	_hit_point = cp._hit_point;
	_energy_point = cp._energy_point;
	_attack_point = cp._attack_point;
};

void ClapTrap::attack(const std::string& target)
{
	if (_hit_point > 0 && _energy_point > 0)
	{
		std::cout << _name << " attacks " << target ;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_point > 0 && _energy_point > 0)
	{
		_hit_point -= amount;
		_energy_point -= 1;
		std::cout << " causing " << amount << " points of damage!" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_point > 0 && _energy_point > 0)
	{
		_hit_point += amount;
		_energy_point -= 1;
		std::cout << "Healing himself " << amount << " healt points!" << std::endl;
	}
}
