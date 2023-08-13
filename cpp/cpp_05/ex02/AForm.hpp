#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	int const _gradeToAssign;
	int const _gradeToExecute;
	bool _isAssigned;
	AForm();

public:
	AForm(std::string name, int const gradeToAssign,
		  int const gradeToExecute);
	virtual ~AForm();
	AForm(AForm const &other);
	AForm &operator=(AForm const &other);
	std::string const getName() const;
	bool getIsAssigned() const;
	int getGradeToAssign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &other);

#endif
