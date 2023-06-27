#include "ScavTrap.hpp"

int main()
{
	ScavTrap trap("Seismic");

	trap.attack("dot");
	trap.takeDamage(1);


	trap.guardGate();
	trap.takeDamage(1);


	return (0);
}
