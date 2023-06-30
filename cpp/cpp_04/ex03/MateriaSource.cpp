#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){ std::cout << "MateriaSource constructor called" << std::endl; }
MateriaSource::~MateriaSource(){ std::cout << "MateriaSource destructor called" << std::endl; }

MateriaSource::MateriaSource(const MateriaSource& cpMateriaSource)
{
	std::cout << "Copy MateriaSource constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "Copy MateriaSource assignment operator called " << std::endl;
	//if (this != &other)

	return (*this);
}
