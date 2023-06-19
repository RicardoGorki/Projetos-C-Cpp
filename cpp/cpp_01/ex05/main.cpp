#include "Harl.hpp"

int main()
{
	Harl		harls;
	int			flag;
	std::string	level;

	flag = 1;
	std::cout << "Insert Harl: DEBUG, INFO, WARNING, ERROR" << std::endl;
	while (flag)
	{
		std::cout << "> ";
		std::getline(std::cin, level);
		if (std::cin.eof())
			flag = 0;
		if (level == "exit" || level == "EXIT")
			return (0);
		harls.complain(level);
	}
	return (0);
}
