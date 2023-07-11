#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	//const Animal* meta = new Animal(); //abstrata não consegue chamar
	const Animal* j = new Dog();
	const Animal* i = new Cat();


	std::cout << std::endl;
	std::cout << "----Dog----" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	std::cout << std::endl;
	std::cout << "----Cat----" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!

	delete j;
	delete i;
	return (0);
}
