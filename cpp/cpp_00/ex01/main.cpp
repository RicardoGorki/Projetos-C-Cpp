#include "PhoneBook.hpp"

int main()
{
	int			control;
	std::string	temp;
	PhoneBook	phone;

	control = 1;
	std::cout << "Enter with options: ADD | SEARCH | EXIT" << std::endl;
	while(control)
	{
		std::getline(std::cin, temp);
		if (std::cin.eof())
			control = 0;
		if (temp == "ADD")
			std::cout << "ENTREI ADD" << std::endl;
		else if (temp == "SEARCH")
			std::cout << "ENTREI SEARCH" << std::endl;
		else if (temp == "EXIT")
		{
			//destroy tudao
			control = 0;
		}
		else
			std::cout << "try only the options: "
					<< "ADD | SEARCH | EXIT" << std::endl;
	}
	return (0);
}
