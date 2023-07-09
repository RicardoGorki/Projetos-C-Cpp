#include "Fixed.hpp"

Fixed::Fixed(void) : _store_fp(0), _store_bit(8){};

Fixed::Fixed(const float floatValue) : _store_bit(8)
{
	_store_fp = ((roundf(floatValue * (1 << _store_bit))));
};

Fixed::Fixed(const int intValue) : _store_bit(8)
{
	_store_fp = intValue * (1 << _store_bit);
};

Fixed::Fixed(const Fixed &other)
{
	_store_fp = other._store_fp;
	_store_bit = other._store_bit;
};

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_store_fp = other._store_fp;
	return (*this);
};

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed result;
    result._store_fp = (_store_fp + other._store_fp);
    return (result);
};

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed result;
    result._store_fp = (_store_fp - other._store_fp);
    return (result);
};

Fixed Fixed::operator*(const Fixed &other)
{
  	Fixed result;
    result._store_fp = (_store_fp * other._store_fp) >> _store_bit;
    return (result);
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed result;
    result._store_fp = (_store_fp / other._store_fp) << _store_bit;
    return (result);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_store_fp < other._store_fp);
};

bool Fixed::operator>(const Fixed &other) const
{
	return (_store_fp > other._store_fp);
};

bool Fixed::operator>=(const Fixed &other) const
{
	return (_store_fp >= other._store_fp);
};

bool Fixed::operator<=(const Fixed &other) const
{
	return (_store_fp <= other._store_fp);
};
bool Fixed::operator==(const Fixed &other) const
{
	return (_store_fp == other._store_fp);
};
bool Fixed::operator!=(const Fixed &other) const
{
	return (_store_fp != other._store_fp);
};

std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return (os);
};

Fixed& Fixed::operator++()
{
	++_store_fp;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_store_fp++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	--_store_fp;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_store_fp--;
	return (temp);
}

Fixed &min(Fixed &a, Fixed &b)
{
	return (a <= b) ? a : b;
};

Fixed &max(Fixed &a, Fixed &b)
{
	return (a >= b) ? a : b;
};

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a <= b) ? a : b;
};

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a >= b) ? a : b;
};

Fixed::~Fixed(void){};

int Fixed::getRawBits(void) const
{
	return (this->_store_fp);
};

void Fixed::setRawBits(int const raw)
{
	this->_store_fp = raw;
};

float Fixed::toFloat(void) const
{
	return ((float)(_store_fp) / (1 << _store_bit));
}

int Fixed::toInt(void) const
{
	return (_store_fp / (1 << _store_bit));
}
