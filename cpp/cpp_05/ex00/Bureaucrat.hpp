#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{

private:
	std::string const _name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	~Bureaucrat();
};

#endif
