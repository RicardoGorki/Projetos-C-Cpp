#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	int const			_gradeToAssign;
	int const			_gradeToExecute;
	bool				_isAssigned;
	Form();

public:
	Form(std::string name, int const gradeToAssign,
		int const gradeToExecute);
	~Form();
	Form(Form const & other);
	Form& operator=(Form const & other);
	std::string const getName() const;
	bool getIsAssigned() const;
	int getGradeToAssign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat bureaucrat);
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

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif
