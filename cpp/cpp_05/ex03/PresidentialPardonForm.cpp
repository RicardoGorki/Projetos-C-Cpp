#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	throw std::logic_error("Cannot use this constructor without parameters");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	_target = (other._target);
};
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	_target = other._target;
	return (*this);
};

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getIsAssigned() == true)
	{
		if (executor.getGrade() <= 5)
		{
			std::cout << "Informs that " << _target << " has been pardoned by Zaphod Beeblebrox. " << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm(){};
