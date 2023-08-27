#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (verifyContent(argv[1]))
			std::cout << "Error" << std::endl;
		else
			calculator(argv[1]);
	}
	else
		std::cout << "Error" << std::endl;
	return 0;
}
