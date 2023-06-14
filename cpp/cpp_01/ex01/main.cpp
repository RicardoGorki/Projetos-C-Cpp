#include "Zombie.hpp"

int main()
{
	Zombie* zombie = zombieHorde(5, "biro");

	delete []zombie;
	return (0);
}
