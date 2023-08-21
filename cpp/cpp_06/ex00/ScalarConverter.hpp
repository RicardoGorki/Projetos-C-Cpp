#ifndef SCALARCOVERTER_HPP
#define SCALARCOVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdlib>

// cstdlib atof atoi atol
// math isnan - e +inf
// climits max min

class ScalarConverter
{
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter &other);
	ScalarConverter &operator=(ScalarConverter &other);
	void convert(std::string szToNum);
};

#endif
