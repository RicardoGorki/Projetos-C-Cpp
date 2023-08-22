#include "Serializer.hpp"

Serializer::Serializer(){};
Serializer::~Serializer(){};
Serializer::Serializer(Serializer &other)
{
	(void)other;
};

Serializer &Serializer::operator=(Serializer &other)
{
	(void)other;
	return (*this);
};

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t newValue = reinterpret_cast<uintptr_t>(ptr);
	return (newValue);
};

Data *Serializer::deserialize(uintptr_t raw)
{
	Data * newData = reinterpret_cast<Data *>(raw);
	return (newData);
};
