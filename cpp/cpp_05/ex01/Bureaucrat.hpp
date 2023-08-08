#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"

class Bureaucrat
{

private:
	const std::string _name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	void signForm(const Form & form);

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
