#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{

protected:
	std::string ideas[100];

public:

	Brain();
	~Brain();
	Brain(const Brain& cpBrain);
	Brain& operator=(const Brain& other);

};

#endif
