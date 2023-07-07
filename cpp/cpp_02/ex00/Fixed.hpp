#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{

private:
	int _store_fp;
	static const int _store_bit;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif
