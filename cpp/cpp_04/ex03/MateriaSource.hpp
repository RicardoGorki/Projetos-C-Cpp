#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

class MateriaSource
{

public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& cpMateriaSource);
	MateriaSource& operator=(const MateriaSource& other);
};

#endif
