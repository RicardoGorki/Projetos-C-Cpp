	#include "Fixed.hpp"

	Fixed::Fixed(void)
	{
		std::cout << "Default constructor called" << std::endl;
		_store_fp = 0;
	};

	Fixed::Fixed(const float floatValue) : _store_fp(static_cast<int>(roundf(floatValue * (1 << _store_bit))))
	{
		std::cout << "Float constructor called" << std::endl;
	}

	Fixed::Fixed(const int intValue) : _store_fp(intValue << _store_bit)
	{
		std::cout << "Int constructor called" << std::endl;
	}

	Fixed::Fixed(const Fixed &other)
	{
		std::cout << "Copy constructor called" << std::endl;
		_store_fp = other._store_fp;
	};

	Fixed& Fixed::operator=(const Fixed& other)
	{
		if (this != &other)
			_store_fp = other._store_fp;
		std::cout << "Copy assignment operator called" << std::endl;
		return (*this);
	};

	std::ostream& operator<<(std::ostream& os, const Fixed& fp)
	{
		os << fp.toFloat();
		return (os);
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

	float Fixed::toFloat(void) const
	{
		return (static_cast<float>(_store_fp) / (1 << _store_bit));
	}

	int Fixed::toInt(void) const
	{
		return (_store_fp >> _store_bit);
	}
