#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Data;

class Serializer
{
private:
	Serializer();

public:
	~Serializer();
	Serializer(Serializer &other);
	Serializer &operator=(Serializer &other);
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);


};

#endif
