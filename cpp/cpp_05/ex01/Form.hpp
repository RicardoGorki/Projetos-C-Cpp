
#include "Bureaucrat.hpp"


class Bureaucrat;

class Form : public Bureaucrat
{
private:
	std::string const _name;
	bool _isAssigned;
	int const _gradeToAssign;
	int const _gradeToExecute;
public:
	Form();
	~Form();
	Form(std::string name, bool isAssigned,
		int const gradeToAssign, int const gradeToExecute);
	Form(Form const & other);
	Form& operator=(Form const & other);
	friend std::ostream& operator<<(std::ostream& os, const Form& other);
	std::string const getName();
	bool getIsAssigned();
	int const getGradeToAssign();
	int const getGradeToExecute();
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
