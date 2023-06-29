#include "FragTrap.hpp"

FragTrap::FragTrap() { std::cout << "Constructor called" << std::endl; }

FragTrap::~FragTrap() { std::cout << "Destructor called" << std::endl; }

FragTrap::FragTrap(const FragTrap &cpFragTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = cpFragTrap._name;
	_hit_point = cpFragTrap._hit_point;
	_energy_point = cpFragTrap._energy_point;
	_attack_point = cpFragTrap._attack_point;
};

void FragTrap::operator=(const FragTrap& cp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_name = cp._name;
	_hit_point = cp._hit_point;
	_energy_point = cp._energy_point;
	_attack_point = cp._attack_point;
};

FragTrap::FragTrap(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	_name = name;
	_hit_point = 100;
	_energy_point = 100;
	_attack_point = 30;
}

void FragTrap::highFivesGuys(void)
{
 std::cout << "positive high fives request on the standard output." << std::endl;
}
