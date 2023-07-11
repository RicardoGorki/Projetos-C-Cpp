#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{

private:

	Brain* _newBrain;

public:

	Cat();
	~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	void makeSound() const;
	std::string getIdea(int i);
	void setIdea();
};



#endif
