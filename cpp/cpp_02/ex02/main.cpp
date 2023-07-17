#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const c(10.01f);
	Fixed d(5);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	//std::cout << c++ << std::endl;
	d = d + c;
	std::cout << d << std::endl;

return 0;
}
