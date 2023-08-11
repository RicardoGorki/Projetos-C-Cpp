#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

class AForm;
class Bureaucrat
{

private:
	Bureaucrat();
	const std::string _name;
	int	_grade;

public:
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	void signAForm(AForm & AForm);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
	std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
