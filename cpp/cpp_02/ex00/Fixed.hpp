#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{

private:
	int _store_fp;
	static const int _store_bit;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &cpFixed);
	void operator=(const Fixed& fp);
	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif
