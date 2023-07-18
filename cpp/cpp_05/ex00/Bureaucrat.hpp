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
	std::string getName() const;
	int getGrade() const;
	friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);
	int GradeTooHighException(int nValue);
	int GradeTooLowException(int nValue);
};

#endif
