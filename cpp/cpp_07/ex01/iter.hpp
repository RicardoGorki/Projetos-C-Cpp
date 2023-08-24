#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename U>
void iter(T const &addr_array, size_t const &len, U const &f)
{
	for (size_t i = 0; i < len; i++)
	{
		f(addr_array[i]);
	}
};

#endif
