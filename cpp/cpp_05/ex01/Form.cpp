#include "Form.hpp"

Form::Form() : _name("Any"), _isAssigned(false), _gradeToAssign(0), _gradeToExecute(0)
{
	throw GradeTooHighException();
};

Form::Form(std::string name, int const gradeToAssign, int const gradeToExecute) : _name(name),
		_gradeToAssign(gradeToAssign),
		_gradeToExecute(gradeToExecute)
{
	_isAssigned = false;
};

Form::Form(Form const & other) : _name(other._name),
		_isAssigned(other._isAssigned), _gradeToAssign(other._gradeToAssign),
		_gradeToExecute(other._gradeToExecute)
{};

Form& Form::operator=(Form const & other)
{
	if (this != &other)
	{
		*const_cast<std::string*>(&_name) = other._name;
		*const_cast<int*>(&_gradeToAssign) = other._gradeToAssign;
		*const_cast<int*>(&_gradeToExecute) = other._gradeToExecute;
		_isAssigned = other._isAssigned;
	}
	return (*this);
};

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << "name " << other.getName() << "grade to assign " << other.getGradeToAssign()
	<< "isAssigned " << other.getIsAssigned() << "grade to execute " << other.getGradeToExecute();
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

int const Form::getGradeToAssign() const
{
	return (this->_gradeToAssign);
}

int const Form::getGradeToExecute() const
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
