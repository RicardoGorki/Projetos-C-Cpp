#include "ScavTrap.hpp"

ScavTrap::ScavTrap() { std::cout << "Constructor called" << std::endl; }

ScavTrap::~ScavTrap() { std::cout << "Destructor called" << std::endl; }

ScavTrap::ScavTrap(const ScavTrap &cpScavTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = cpScavTrap._name;
	_hit_point = cpScavTrap._hit_point;
	_energy_point = cpScavTrap._energy_point;
	_attack_point = cpScavTrap._attack_point;
};

void ScavTrap::operator=(const ScavTrap& cp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_name = cp._name;
	_hit_point = cp._hit_point;
	_energy_point = cp._energy_point;
	_attack_point = cp._attack_point;
};

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	_name = name;
	_hit_point = 100;
	_energy_point = 50;
	_attack_point = 20;
}

void ScavTrap::guardGate()
{
 std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
