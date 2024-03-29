#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Clap_Anonimous"), _hit_point(10), _energy_point (10), _attack_point(0) { std::cout << "ClapTrap constructor called" << std::endl;}


ClapTrap::ClapTrap(std::string name) : _name(name), _hit_point(10), _energy_point (10), _attack_point(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	_name = other._name;
	_hit_point = other._hit_point;
	_energy_point = other._energy_point;
	_attack_point = other._attack_point;
};

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	_name = other._name;
	_hit_point = other._hit_point;
	_energy_point = other._energy_point;
	_attack_point = other._attack_point;
	return (*this);
};

void ClapTrap::attack(const std::string& target)
{
	if (_hit_point > 0 && _energy_point > 0)
	{
		_energy_point -= 1;
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing "
			<< _attack_point << " points of damage!" << std::endl;
		std::cout << _name << " HP: " << _hit_point << " Ene: " << _energy_point << std::endl;
	}

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_point > 0)
	{
		_hit_point -= amount;
		std::cout << "ClapTrap " << _name << " take " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << _name << " you already dead" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_point > 0 && _energy_point > 0)
	{
		_hit_point += amount;
		_energy_point -= 1;
		std::cout << "ClapTrap Healing himself " << amount << " healt points!" << std::endl;
		std::cout << _name << " HP: " << _hit_point << " Ene: " << _energy_point << std::endl;
	}

}
