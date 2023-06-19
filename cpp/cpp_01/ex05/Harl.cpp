#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Constructor called" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Destructor called" << std::endl;
}

void Harl::debug(void)
{
	std::cout	<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-specialketchup burger."
				<< " I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout	<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn’t put enough bacon in my burger! If you did, "
				<< "I wouldn’t be asking for more!"
				<< std::endl;
}
void Harl::warning(void)
{
	std::cout	<< "I think I deserve to have some extra bacon for free."
				<< "I’ve been coming for years whereas you started"
				<< "working here since last month."
				<< std::endl;
}
void Harl::error(void)
{
	std::cout	<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}




void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl obj;
	int op;
	int i;

	op = 4;
	for (i = 0; i < 4 ; i++)
	{
		if (level == levels[i])
		{
			op = i;
			break;
		}
	}
	void (Harl::*ptr)();
	switch (op)
	{
	case 0:
		ptr = &Harl::debug;
		(obj.*ptr)();
		break;
	case 1:
		ptr = &Harl::info;
		(obj.*ptr)();
		break;
	case 2:
		ptr = &Harl::warning;
		(obj.*ptr)();
		break;
	case 3:
		ptr = &Harl::error;
		(obj.*ptr)();
		break;
	default:
		break;
	}
	return ;
}
