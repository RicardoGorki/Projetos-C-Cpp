#include "PhoneBook.hpp"

void header_view()
{
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "|                          \033[0;36mPhoneBook\033[0m                                |" << std::endl;
	std::cout << "|                                                                   |" << std::endl;
	std::cout << "| Enter with any comands below:                                     |" << std::endl;
	std::cout << "| \033[0;31mADD\033[0m    add new contact                                            |" << std::endl;
	std::cout << "| \033[0;31mSEARCH\033[0m search for a contact                                       |" << std::endl;
	std::cout << "| \033[0;31mEXIT\033[0m   exit the program                                           |" << std::endl;
	std::cout << "|                                                                   |" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
}

int main()
{
	int			flag;
	int			index;
	std::string	str;
	PhoneBook	phone;

	flag = 1;
	index = 0;
	header_view();
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
