#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

//class IMateriaSource;
class MateriaSource
{

public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& cpMateriaSource);
	MateriaSource& operator=(const MateriaSource& other);
	void learnMateria(AMateria*);
	MateriaSource& createMateria(std::string const &);

};

#endif
