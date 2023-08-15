#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class RobotomyRequestForm;
class PresidentialPardonForm;
class ShrubberyCreationForm;
class AForm;

class Intern
{

public:
	Intern();
	~Intern();
	Intern(Intern &other);
	Intern &operator=(Intern &other);
	AForm *makeForm(std::string nameForm, std::string targetForm);
};

#endif
