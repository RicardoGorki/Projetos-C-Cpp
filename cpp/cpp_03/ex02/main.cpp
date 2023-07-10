#include "FragTrap.hpp"

int main()
{
	FragTrap fTrap("C3PO");
	FragTrap trap(fTrap);

	trap.attack("Stormtrooper");
	trap.takeDamage(30);
	trap.highFivesGuys();


	return (0);
}
