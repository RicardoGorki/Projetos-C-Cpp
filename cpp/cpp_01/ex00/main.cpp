#include "Zombie.hpp"

int main()
{
	Zombie* zombie = newZombie("biro");
	randomChump("mestrim");
	//zombie->announce();
	delete zombie;
	return (0);
}
