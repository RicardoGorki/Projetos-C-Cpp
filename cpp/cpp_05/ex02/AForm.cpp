#include "AForm.hpp"

AForm::AForm(std::string name, int const gradeToAssign, int const gradeToExecute) : _name(name),
		_gradeToAssign(gradeToAssign), _gradeToExecute(gradeToExecute), _isAssigned(false) {};


AForm::AForm(AForm const & other) : _name(other._name),
		_gradeToAssign(other._gradeToAssign),
		_gradeToExecute(other._gradeToExecute),
		_isAssigned(other._isAssigned)
{};

AForm& AForm::operator=(AForm const & other)
{
	if (this != &other)
		_isAssigned = other._isAssigned;
	return (*this);
};

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os << "name: " << other.getName() << ", grade to assign: " << other.getGradeToAssign()
	<< ", isAssigned: " << other.getIsAssigned() << ", grade to execute: " << other.getGradeToExecute();
	return (os);
}

std::string const AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsAssigned() const
{
	return (this->_isAssigned);
}

int AForm::getGradeToAssign() const
{
	return (_gradeToAssign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= getGradeToAssign())
		_isAssigned = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!\n");
};

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!\n");
};

AForm::~AForm() {};
