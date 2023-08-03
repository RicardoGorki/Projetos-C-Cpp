#include "Form.hpp"

Form::Form() : _name("Any"), _isAssigned(false), _gradeToAssign(0), _gradeToExecute(0)
{
	throw GradeTooHighException();
};

Form::Form(std::string name, bool isAssigned,
		int const gradeToAssign, int const gradeToExecute) : _name(name),
		_isAssigned(false), _gradeToAssign(gradeToAssign),
		_gradeToExecute(gradeToExecute)
{

};

Form::Form(Form const & other) : _name(other._name),
		_isAssigned(false), _gradeToAssign(other._gradeToAssign),
		_gradeToExecute(other._gradeToExecute)
{};

Form& Form::operator=(Form const & other)
{
	_name = other._name;
	_isAssigned = other._isAssigned;
	return (*this);
};

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << other._name;
	// Precisa terminar
	return (os);
}

std::string const Form::getName()
{
	return (this->_name);
}

bool Form::getIsAssigned()
{
	return (this->_isAssigned);
}

int const Form::getGradeToAssign()
{
	return (this->_gradeToAssign);
}

int const Form::getGradeToExecute()
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat bureaucrat)
{

}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!\n");
};

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!\n");
};
