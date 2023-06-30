#include "Ice.hpp"

Ice::Ice(){std::cout << "Ice constructor called " << std::endl;}

Ice::~Ice() {std::cout << "Ice destructor called " << std::endl;}

Ice::Ice(const Ice& cpIce){
	std::cout << "Copy Ice constructor called " << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Copy Ice assignment operator called " << std::endl;
}
