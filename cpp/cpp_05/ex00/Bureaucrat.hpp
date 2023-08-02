#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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
	friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);
	void increment();
	void decrement();

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

#endif
