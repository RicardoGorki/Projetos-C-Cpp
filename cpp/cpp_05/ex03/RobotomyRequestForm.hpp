#ifndef ROBOTOMYREQUESTFORM_CPP
# define ROBOTOMYREQUESTFORM_CPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	void execute(Bureaucrat const & executor) const;
	~RobotomyRequestForm();
};

#endif
