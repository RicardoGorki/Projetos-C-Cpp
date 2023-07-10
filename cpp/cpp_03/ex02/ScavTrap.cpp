#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
std::cout << "ScavTrap constructor called" << std::endl;
	_name = "Scav_Anonimous";
	_hit_point = 100;
	_energy_point = 50;
	_attack_point = 20;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap()
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_name = other._name;
	_hit_point = other._hit_point;
	_energy_point = other._energy_point;
	_attack_point = other._attack_point;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	_name = other._name;
	_hit_point = other._hit_point;
	_energy_point = other._energy_point;
	_attack_point = other._attack_point;
	return (*this);
};

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_name = name;
	_hit_point = 100;
	_energy_point = 50;
	_attack_point = 20;
}

void ScavTrap::guardGate()
{
	if (_hit_point > 0)
 		std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hit_point > 0 && _energy_point > 0)
	{
		_energy_point -= 1;
		std::cout << "Scavtrap " << _name << " attacks " << target << " causing "
			<< _attack_point << " points of damage!" << std::endl;
		std::cout << _name << " HP: " << _hit_point << " Ene: " << _energy_point << std::endl;
	}

}
