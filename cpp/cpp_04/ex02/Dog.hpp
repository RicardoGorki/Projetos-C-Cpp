#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal
{

private:

	Brain* _newBrain;

public:

	Dog();
	~Dog();
	Dog(const Dog& cpDog);
	Dog& operator=(const Dog& other);
	void makeSound() const;

};

#endif
