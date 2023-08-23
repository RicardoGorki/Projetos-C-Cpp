#include "Data.hpp"
#include "Serializer.hpp"

int main ()
{
	unsigned int nValue = 42;
	Data *dataValue = new Data(nValue);

	uintptr_t serial = Serializer::serialize(dataValue);
	Data * deserial = Serializer::deserialize(serial);

	std::cout << "data:\t" << dataValue->getValue() << std::endl;
	std::cout << "data:\t" << dataValue << std::endl;
	std::cout << "ser:\t" << serial << std::endl;
	std::cout << "des:\t" << deserial << std::endl;
	std::cout << "des:\t" << deserial->getValue() << std::endl;


	delete dataValue;
	return (0);
}
