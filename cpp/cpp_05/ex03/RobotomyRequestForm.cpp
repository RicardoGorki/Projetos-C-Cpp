#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	_target = (other._target);
};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	_target = other._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

	if (getIsAssigned() == true)
	{
		if (executor.getGrade() <= 45)
		{
			std::srand(std::time(NULL));
			std::cout << "zum zum zum" << std::endl;
			int random = std::rand() % 100;
			if (random < 50)
				std::cout << _target << " has been robotomized successfully 50% of the time. " << std::endl;
			else
				std::cout << _target << " the robotomy failed." << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw GradeTooLowException();
}

RobotomyRequestForm::~RobotomyRequestForm(){};
