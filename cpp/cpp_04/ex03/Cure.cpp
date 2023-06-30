#include "Cure.hpp"

Cure::Cure(){ std::cout << "Cure constructor called " << std::endl; }
Cure::~Cure(){std::cout << "Cure destructor called " << std::endl; }

Cure::Cure(const Cure& cpCure)
{
	std::cout << "Copy constructor called " << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Copy Cure assignment operator called " << std::endl;
	return (*this);
}
