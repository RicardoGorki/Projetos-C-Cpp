#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_store_fp = 0;
};

Fixed::Fixed(const Fixed &cpFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	_store_fp = cpFixed._store_fp;
};

void Fixed::operator=(const Fixed& fp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_store_fp = fp._store_fp;
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
