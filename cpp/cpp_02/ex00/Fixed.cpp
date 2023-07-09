#include "Fixed.hpp"

Fixed::Fixed(void) : _store_fp(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_store_fp = other._store_fp;
};

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_store_fp = other._store_fp;
	return (*this);
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_store_fp);
};

void Fixed::setRawBits(int const raw)
{
	this->_store_fp = raw;
};
