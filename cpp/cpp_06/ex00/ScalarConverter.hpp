#ifndef SCALARCOVERTER_HPP
#define SCALARCOVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter &other);
	ScalarConverter &operator=(ScalarConverter &other);
	static void handleError(std::string szToNumber);
	static int identifyType(std::string szToNumber);
	static void convertToChar(std::string szToNumber);
	static void convertToInt(std::string szToNumber);
	static void convertToFloat(std::string szToNumber);
	static void convertToDouble(std::string szToNumber);

public:
	static void convert(std::string szToNumber);

};

#endif
