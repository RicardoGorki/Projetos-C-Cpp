#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Gov", 2);
		Form form("Odeb", 40, 50);

		std::cout << (bureaucrat) << std::endl;
		std::cout << (form) << std::endl;
		bureaucrat.signForm(form);

	}
	catch (std::exception& e)
    {
       std::cout << e.what() << std::endl;
    }
	return (0);
};
