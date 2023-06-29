#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* a[50];

for(int i = 0; i < 50; i++)
{
	if (i%2 == 0)
		a[i] = new Dog();
	else
		a[i] = new Cat();
}

for(int i = 0; i < 50; i++)
	delete a[i];

}
