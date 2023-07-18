#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("anonymous")
{
	std::cout << "Constructor called" << std::endl;
	try
	{
		if (!_grade)
			throw(_grade);
	}
	catch (int e)
	{
		std::cout << e << "Need set value to grade" << std::endl;
	}
};

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor called" << std::endl;
	try
	{
		if (!_grade)
			throw(_grade);
		else if (_grade < 1)
			throw(Bureaucrat::GradeTooHighException(_grade));
		else if (_grade > 150)
			throw(Bureaucrat::GradeTooLowException(_grade));
	}
	catch (int &e)
	{
		std::cout << e << std::endl;
	}
};

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other._name << " , bureaucrat grade " << other._grade;
	return (os);
};

int Bureaucrat::GradeTooHighException(int nValue)
{
	std::cout << "Grade too hight" << std::endl;
	return (nValue);
};

int Bureaucrat::GradeTooLowException(int nValue)
{
	std::cout << "Grade too low" << std::endl;
	return (nValue);
};

Bureaucrat::~Bureaucrat(){};
