#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <iostream>

template<typename T>
void easyfind(T const &x, int y)
{
	for (typename T::const_iterator i = x.begin(); i != x.end(); i++ )
	{
		if (*i == y)
		{
			std::cout << "Found " << y << " in container!" << std::endl;
			return ;
		}

	}
	throw std::logic_error("Value not found");
};

#endif
