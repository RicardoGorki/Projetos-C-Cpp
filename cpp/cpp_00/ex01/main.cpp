#include "PhoneBook.hpp"

int main()
{
	int			flag;
	int			index;
	std::string	str;
	PhoneBook	phone;

	flag = 1;
	index = 0;
	std::cout << "Enter with commands: ADD | SEARCH | EXIT" << std::endl;
	while(flag)
	{
		std::cout << "Enter with a command: " << std::endl;
		std::getline(std::cin, str);
		if (std::cin.eof())
			flag = 0;
		if (str == "ADD")
		{
			phone.add_contact(index);
			index++;
			if (index == 8)
				index = 0;
		}
		else if (str == "SEARCH")
			phone.search_contact();
		else if (str == "EXIT")
			flag = 0;
		else
			std::cout << "try only the options: "
					<< "ADD | SEARCH | EXIT" << std::endl;
	}
	return (0);
}
