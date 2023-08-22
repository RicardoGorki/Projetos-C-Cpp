#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){};

Base *generate(void)
{
	std::srand(std::time(NULL));
	int random = std::rand() % 3;
	int op = random;
	switch (op)
	{
	case 0:
		std::cout << "A " << std::endl;
		return (new A());
		break;
	case 1:
		std::cout << "B " << std::endl;
		return (new B());
		break;
	case 2:
		std::cout << "C " << std::endl;
		return (new C());
		break;
	default:
		break;
	}
	return (NULL);
};

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		A *a = dynamic_cast<A *>(p);
		std::cout << "ptr A: " << a << std::endl;
		return;
	}
	if (dynamic_cast<B *>(p) != NULL)
	{
		B *b = dynamic_cast<B *>(p);
		std::cout << "ptr B: " << b << std::endl;
		return;
	}
	if (dynamic_cast<C *>(p) != NULL)
	{
		C *c = dynamic_cast<C *>(p);
		std::cout << "ptr C: " << c << std::endl;
		return;
	}
};

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "ref A: " << &a << std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "ref B: " << &b << std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "ref C: " << &c << std::endl;
	}
	catch (std::exception &e)
	{}
};

/* if (dynamic_cast<A>(&p) != NULL)
{
	A a = dynamic_cast<A>(&p);
	std::cout << "ref A: " << a << std::endl;
	return;
}
if (dynamic_cast<B *>(&p) != NULL)
{
	B *b = dynamic_cast<B *>(&p);
	std::cout << "ref B: " << b << std::endl;
	return;
}
if (dynamic_cast<C *>(&p) != NULL)
{
	C *c = dynamic_cast<C *>(&p);
	std::cout << "ref C: " << c << std::endl;
	return;
} */

