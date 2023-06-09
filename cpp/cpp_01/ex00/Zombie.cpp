#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << ": destructor called" << std::endl;
}

std::string	Zombie::getName() const
{
	return (this->_name);
}

void	Zombie::setName(const std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
