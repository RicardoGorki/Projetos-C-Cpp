#include "iter.hpp"

template <typename T>
void foo(T many)
{
	std::cout << many << std::endl;
};

int main(void)
{

	int nArray[] = {0, 1, 2, 4, 7, 8};
	std::string szArray[4] = {"banana", "abacaxi", "pera", "uva"};

	::iter(nArray, 5, foo<int>);
	::iter(szArray, 3, foo<std::string>);
	return (0);
}
