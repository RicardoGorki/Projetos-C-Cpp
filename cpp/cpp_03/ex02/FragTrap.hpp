#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

protected:


public:
	FragTrap();
	~FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &cpFragTrap);
	void operator=(const FragTrap& cp);
	void highFivesGuys(void);
};

#endif
