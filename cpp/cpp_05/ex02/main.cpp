#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Gov", 2);
		//AForm AForm("Odeb", 40, 50);

		std::cout << (bureaucrat) << std::endl;
		//std::cout << (AForm) << std::endl;
		//bureaucrat.signAForm(AForm);

	}
	catch (std::exception& e)
    {
       std::cout << e.what() << std::endl;
    }
	return (0);
};
