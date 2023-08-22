#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main ()
{
	Base * newBase = generate();

	identify(newBase);
	identify(*newBase);
	return (0);
}
