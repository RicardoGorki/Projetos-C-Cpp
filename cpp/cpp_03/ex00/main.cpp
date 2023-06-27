#include "ClapTrap.hpp"

int main()
{
	ClapTrap trap("Seismic");

	trap.attack("rat");
	trap.takeDamage(9);
	trap.beRepaired(100);
	trap.attack("urubu");
	trap.takeDamage(10);
	trap.attack("urubu");
	trap.takeDamage(10);

	std::cout << trap.getName();

	return (0);
}
