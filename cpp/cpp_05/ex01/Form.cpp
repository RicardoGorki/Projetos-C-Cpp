#include "Form.hpp"

Form::Form(std::string name, int const gradeToAssign) : _name(name),
		_gradeToAssign(gradeToAssign), _gradeToExecute(0), _isAssigned(false) {};


Form::Form(Form const & other) : _name(other._name),
		_gradeToAssign(other._gradeToAssign),
		_gradeToExecute(other._gradeToExecute),
		_isAssigned(other._isAssigned)
{};

Form& Form::operator=(Form const & other)
{
	if (this != &other)
		_isAssigned = other._isAssigned;
	return (*this);
};

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << "name: " << other.getName() << ", grade to assign: " << other.getGradeToAssign()
	<< ", isAssigned: " << other.getIsAssigned();
	return (os);
}

std::string const Form::getName() const
{
	return (this->_name);
}

bool Form::getIsAssigned() const
{
	return (this->_isAssigned);
}

int Form::getGradeToAssign() const
{
	return (_gradeToAssign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= getGradeToAssign())
		_isAssigned = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!\n");
};

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!\n");
};

Form::~Form() {};
