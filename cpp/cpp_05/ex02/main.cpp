#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Gov", 5);
		PresidentialPardonForm presidential("SupremoGift");
		bureaucrat.signAForm(presidential);
		presidential.execute(bureaucrat);
		 std::cout << (bureaucrat) << std::endl;
		 std::cout << (presidential) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << std::endl;
		Bureaucrat bureaucrat("Gov", 5);
		RobotomyRequestForm robo("C3PO");
		bureaucrat.signAForm(robo);
		robo.execute(bureaucrat);
		 std::cout << (bureaucrat) << std::endl;
		 std::cout << (robo) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << std::endl;
		Bureaucrat bureaucrat("Gov", 5);
		ShrubberyCreationForm tree("Grooty");
		bureaucrat.signAForm(tree);
		tree.execute(bureaucrat);
		 std::cout << (bureaucrat) << std::endl;
		 std::cout << (tree) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
};
