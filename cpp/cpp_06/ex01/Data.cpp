#include "Data.hpp"

Data::Data(unsigned int unValue) : _unValue(unValue) {};
Data::~Data(){};
Data::Data(Data &other)
{
	_unValue = other._unValue;
};
Data &Data::operator=(Data &other)
{
	_unValue = other._unValue;
	return (*this);
};

unsigned int Data::getValue()
{
	return (_unValue);
}
