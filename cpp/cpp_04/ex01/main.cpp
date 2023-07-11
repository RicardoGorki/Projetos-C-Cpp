#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
const Animal* a[50];
Cat b;
Cat c;

for(int i = 0; i < 50; i++)
{
	if (i%2 == 0)
		a[i] = new Dog();
	else
		a[i] = new Cat();
}

for(int i = 0; i < 50; i++)
	delete a[i];

std::cout << std::endl << std::endl;
b.setIdea("Antes do clone", 0);
std::cout << "get b: " <<(b.getIdea(0)) << std::endl;
std::cout << std::endl;

c = b;
std::cout << std::endl;
std::cout << "c copia do b: " << c.getIdea(0) << std::endl;

std::cout << std::endl;
b.setIdea("Depois do clone", 0);
std::cout << "modificando b: " << b.getIdea(0) << std::endl;

std::cout << "Deep Copy: " << c.getIdea(0) << std::endl;
std::cout << std::endl << std::endl;
}
