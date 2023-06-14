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

int check_onlyspace(std::string str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (str.empty())
		return (1);
	while(str[i])
	{
		if (str[i] != 32 && str[i] != 10)
			flag++;
		i++;
	}
	if (flag != 0)
		return (0);
	return (1);
}

int check_has_space(std::string str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (str.empty())
		return (1);
	while(str[i])
	{
		if ((str[i] == 32 && str[i] != 10) || isdigit(str[i]))
			flag++;
		i++;
	}
	if (flag != 0)
		return (1);
	return (0);
}

int my_isdigit(std::string str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void PhoneBook::add_contact(int index)
{
	int			flag;
	std::string str[5];

	flag = 1;
	while(flag)
	{
		std::cout << "\033[0;31mEnter with First Name\033[0m" << std::endl;
		std::getline(std::cin, str[0]);
		if (check_has_space(str[0]) || !my_isdigit(str[0]))
			break ;

		std::cout << "\033[0;31mEnter with Last Name\033[0m" << std::endl;
		std::getline(std::cin, str[1]);
		if (check_has_space(str[1]) || !my_isdigit(str[1]))
			break ;

		std::cout << "\033[0;31mEnter with Nick Name\033[0m" << std::endl;
		std::getline(std::cin, str[2]);
		if (check_onlyspace(str[2]))
			break ;

		std::cout << "\033[0;31mEnter with Phone Number\033[0m" << std::endl;
		std::getline(std::cin, str[3]);
		if (check_onlyspace(str[3]) || my_isdigit(str[3]))
			break ;

		std::cout << "\033[0;31mEnter with Darkest Secret\033[0m" << std::endl;
		std::getline(std::cin, str[4]);
		if (check_onlyspace(str[4]))
			break ;

		if (!str[0].empty() && !str[1].empty() && !str[2].empty()
			&& !str[3].empty() && !str[4].empty())
		{
			this->_contact[index].setFirstName(str[0]);
			this->_contact[index].setLastName(str[1]);
			this->_contact[index].setNickName(str[2]);
			this->_contact[index].setPhoneNumber(str[3]);
			this->_contact[index].setDarkestSecret(str[4]);
			std::cout << "\033[0;32mContact registred with Success\033[0m" << std::endl;
			if (_count_contact < 8)
				_count_contact++;
		}
		flag = 0;
	}
}

void search_view()
{
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "|                              \033[0;36mSEARCH\033[0m                               |" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "|      \033[1mINDEX\033[0m     |   \033[1mFIRST NAME\033[0m   |   \033[1mLAST NAME\033[0m    |   \033[1mNICK NAME\033[0m    |" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
}

void index_view()
{
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|                                       \033[0;36mCONTACT\033[0m                                     |" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|   \033[1mINDEX\033[0m    | \033[1mFIRST NAME\033[0m "
				 "| \033[1mLAST NAME\033[0m  | \033[1mNICK NAME\033[0m  "
				 "| \033[1mPHONE NUMBER\033[0m | \033[1mDARKEST SECRET\033[0m |" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
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
	<<  std::setw(10) << i << "   "
	<< "|   "
	<<  std::setw(10) << format_contact(_contact[i].getFirstName()) << "   "
	<< "|   "
	<<  std::setw(10) << format_contact(_contact[i].getLastName()) <<  "   "
	<< "|   "
	<<  std::setw(10) << format_contact(_contact[i].getNickName()) <<  "   "
	<< "|   "
	<< std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
}

void PhoneBook::index_contact(int i)
{
	if (!_contact[i].getFirstName().empty())
	{
		std::cout << "| "
		<<  std::setw(10) << i << " "
		<< "| "
		<<  std::setw(10) << format_contact(_contact[i].getFirstName()) << " "
		<< "| "
		<<  std::setw(10) << format_contact(_contact[i].getLastName()) <<  " "
		<< "| "
		<<  std::setw(10) << format_contact(_contact[i].getNickName()) <<  " "
		<< "|  "
		<<  std::setw(10) << format_contact(_contact[i].getPhoneNumber()) <<  "  "
		<< "|   "
		<<  std::setw(10) << format_contact(_contact[i].getDarkestSecret()) <<  "   "
		<< "| "
		<< std::endl;
		std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	}
	else
	{
		std::cout << "|                                 \033[0;31mcontact not found\033[0m                                 |" << std::endl;
		std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	}
}

void PhoneBook::search_contact()
{
	std::string	str;
	int 		i;
	int			index;

	i = 0;
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
	if (_count_contact != 0)
	{
		std::cout << "Insert INDEX contact to see more detail" << std::endl;
		std::getline(std::cin, str);
		if (check_onlyspace(str) || !my_isdigit(str))
		{
			index = atoi(str.c_str());
			if (index >= 0 && index <= 7)
			{
				index_view();
				index_contact(index);
			}
			else
			std::cout << "Insert index range [0-7]" << std::endl;
		}
		else
			std::cout << "Only numbers range [0-7]" << std::endl;
	}
}
