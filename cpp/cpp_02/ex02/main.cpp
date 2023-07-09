#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a, c(10);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "X: " <<( ++c) << std::endl;
	std::cout << "X: " <<( c++) << std::endl;
return 0;
}
