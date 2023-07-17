#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("")
{

	_grade();
};
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{

}

Bureaucrat::~Bureaucrat(){};
