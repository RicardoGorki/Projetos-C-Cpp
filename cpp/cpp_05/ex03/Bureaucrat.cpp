#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	throw std::logic_error("Cannot use this constructor without parameters");
};

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Constructor called " << _name << " " << _grade << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
};

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::increment()
{

	if (_grade > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
};

void Bureaucrat::decrement()
{
	if (_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (os);
};

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!\n");
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!\n");
};

void Bureaucrat::signAForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn’t sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
};

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(){};
