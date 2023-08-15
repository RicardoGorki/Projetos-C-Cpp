#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137),_target(target)
{};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	_target = other._target;
};
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	_target = other._target;
	return (*this);
};

void ShrubberyCreationForm::treeGenerator(std::ofstream &newFile) const
{
	 newFile << "Hello, world!" << std::endl;
};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getIsAssigned() == true)
	{
		if (executor.getGrade() <= 137)
		{
			std::ofstream newFile(( _target + "_shrubbery").c_str());
			if (newFile.is_open())
        	{
				treeGenerator(newFile);
				newFile.close();
			}
		}
		else
			throw GradeTooLowException();
	}
	else
		throw GradeTooLowException();
};

ShrubberyCreationForm::~ShrubberyCreationForm(){};
