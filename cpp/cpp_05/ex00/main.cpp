#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat* b = new Bureaucrat("Biro", 2);
	 	Bureaucrat* low = new Bureaucrat("Juice", 1);
		Bureaucrat* high = new Bureaucrat("Apple", 150);

		std::cout << (*b) << std::endl;
		b->increment();
		std::cout << (*b) << std::endl;
	 	std::cout << (*low) << std::endl;
		std::cout << (*high) << std::endl;

		delete b;
	 	delete low;
		delete high;
	}
	catch (std::exception& e)
    {
       std::cout << e.what() << std::endl;
    }
	return (0);
};
