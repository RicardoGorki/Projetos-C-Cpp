#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria
{

protected:
	std::string type;

public:
	AMateria();
	~AMateria();
	AMateria(const AMateria& cpAMateria);
	AMateria(std::string const & type);
	AMateria& operator=(const AMateria& other);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
