#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat* b = new Bureaucrat("Biro", 110);
	std::cout << (*b) << std::endl;

	return (0);
};
