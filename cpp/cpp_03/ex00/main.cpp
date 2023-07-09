#include "ClapTrap.hpp"

int main()
{
	ClapTrap trap("C3PO");

	trap.attack("stormtrooper");
	trap.takeDamage(9);
	trap.beRepaired(100);
	trap.beRepaired(100);
	trap.beRepaired(100);
	trap.beRepaired(100);
	trap.beRepaired(100);
	trap.beRepaired(100);
	trap.beRepaired(100);
	trap.beRepaired(100);
	trap.beRepaired(100);
	trap.beRepaired(100);
	trap.attack("stormtrooper");
	trap.takeDamage(1001);
	trap.attack("stormtrooper");
	trap.takeDamage(1);
	trap.takeDamage(1);
	trap.beRepaired(100);
	trap.attack("stormtrooper");
	return (0);
}
