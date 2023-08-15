#include "Intern.hpp"

Intern::Intern(){};

Intern::Intern(Intern &other)
{
	(void)other;
};

Intern &Intern::operator=(Intern &other)
{
	(void)other;
	return (*this);
};

AForm *Intern::makeForm(std::string nameForm, std::string targetForm)
{
	std::string levels[4] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int op;
	int i;

	op = 3;
	for (i = 0; i < 3; i++)
	{
		if (nameForm == levels[i])
		{
			op = i;
			std::cout << "Intern creates " << targetForm << std::endl;
			break;
		}
	}
	switch (op)
	{
	case 0:
		return new RobotomyRequestForm(targetForm);
		break;
	case 1:
		return new PresidentialPardonForm(targetForm);
		break;
	case 2:
		return new ShrubberyCreationForm(targetForm);
		break;
	default:
		throw std::logic_error("name of this form does not exist");
		break;
	}
	return (NULL);
};

Intern::~Intern(){};
