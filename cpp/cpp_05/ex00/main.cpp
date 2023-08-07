#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat* b = new Bureaucrat("Banana", 2);
	 	Bureaucrat* low = new Bureaucrat("Juice", 1);
		Bureaucrat* high = new Bureaucrat("Apple", 150);

		b->increment();
		std::cout << (*b) << std::endl;
		b->decrement();
		b->decrement();
		b->decrement();
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
