#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Contructor called" << std::endl;
	_count_contact = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Destructor called" << std::endl;
}

void PhoneBook::add_contact(int index)
{
	int			flag;
	std::string str;

	flag = 1;
	if (_count_contact < 8)
		_count_contact++;
	while(flag)
	{
		std::cout << "\033[0;31mEnter with First Name\033[0m" << std::endl;
		std::getline(std::cin, str);
		if (!str.empty())
			PhoneBook::_contact[index].setFirstName(str);
		else
			flag = 0;
		std::cout << "\033[0;31mEnter with Last Name\033[0m" << std::endl;
		std::getline(std::cin, str);
		this->_contact[index].setLastName(str);
		std::cout << "\033[0;31mEnter with Nick Name\033[0m" << std::endl;
		std::getline(std::cin, str);
		this->_contact[index].setNickName(str);
		std::cout << "\033[0;31mEnter with Phone Number\033[0m" << std::endl;
		std::getline(std::cin, str);
		this->_contact[index].setPhoneNumber(str);
		std::cout << "\033[0;31mEnter with Darkest Secret\033[0m" << std::endl;
		std::getline(std::cin, str);
		this->_contact[index].setDarkestSecret(str);
		std::cout << "\033[0;32mContact registred with Success\033[0m" << std::endl;
		flag = 0;
	}
}

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

void search_view()
{
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "|                              \033[0;36mSEARCH\033[0m                               |" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "|      \033[1mINDEX\033[0m     |   \033[1mFIRST NAME\033[0m   |   \033[1mLAST NAME\033[0m    |   \033[1mNICK NAME\033[0m    |" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
}

std::string PhoneBook::format_contact(std::string get_name)
{
	std::string temp;

	temp = get_name;
	if (temp.length() > 10)
		temp = temp.substr(0, 9) + ".";
	return (temp);
}

void PhoneBook::body_contact(int i)
{

	std::cout << "|   "
	<<  std::setw(10) << format_contact(_contact[i].getFirstName()) << "   "
	<< "|   "
	<<  std::setw(10) << format_contact(_contact[i].getLastName()) <<  "   "
	<< "|   "
	<<  std::setw(10) << format_contact(_contact[i].getNickName()) <<  "   "
	<< "|   "
	<<  std::setw(10) << format_contact(_contact[i].getPhoneNumber()) << "   "
	<< "|   "
	<< std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
}

void PhoneBook::search_contact()
{
	int i;

	i = 0;
	header_view();
	search_view();
	if (_count_contact == 0)
	{
		std::cout << "|                         \033[0;31mempty contact list\033[0m                        |" << std::endl;
		std::cout << "---------------------------------------------------------------------" << std::endl;
	}
	while(i < _count_contact)
	{
		body_contact(i);
		i++;
	}
}
