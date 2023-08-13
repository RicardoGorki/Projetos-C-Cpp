#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target)
{
	//execute();
};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : _target(other._target)
{

};
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	_target = other._target;
	return (*this);
};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

}
PresidentialPardonForm::~PresidentialPardonForm(){};
