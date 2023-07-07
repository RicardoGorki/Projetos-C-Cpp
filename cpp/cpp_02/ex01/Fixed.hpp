#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{

private:
	int _store_fp;
	static const int _store_bit = 8;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const float floatValue);
	Fixed(const int intValue);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	friend std::ostream& operator<<(std::ostream& os, const Fixed& fp);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

};

#endif
