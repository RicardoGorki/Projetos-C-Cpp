#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};
ScalarConverter::ScalarConverter(ScalarConverter &other)
{
	(void)other;
};
ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	(void)other;
	return (*this);
};

 std::string ScalarConverter::handleError(std::string szToNumber)
{
	double checkValue;
	checkValue = atof(szToNumber.c_str());
	for (int i = 0 ; i < szToNumber[i] ; i++)
	{
		if (!std::isdigit(szToNumber[i]) && checkValue == 0.0)
			return ("nan");
	}
	return (szToNumber);
}

void ScalarConverter::convertToChar(std::string szToNumber)
{
	if (szToNumber == "nan" || szToNumber == "+inf" || szToNumber == "-inf")
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	char newValue;
	newValue = static_cast<char>(atof(szToNumber.c_str()));
	if (newValue < 32 || newValue > 126)
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	else
	{
		std::cout << "'" <<  newValue << "'" << std::endl;
		return ;
	}
};

void ScalarConverter::convertToInt(std::string szToNumber)
{
	if (szToNumber == "nan" || szToNumber == "+inf" || szToNumber == "-inf")
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	int newValue;
	newValue = static_cast<int>(atof(szToNumber.c_str()));
	if (newValue < INT_MIN || newValue > INT_MAX)
	{
		std::cout << "overflow" << std::endl;
		return ;
	}
	else
	{
		std::cout << newValue << std::endl;
		return ;
	}
};

void ScalarConverter::convertToFloat(std::string szToNumber)
{
	float newValue;
	newValue = static_cast<float>(atof(szToNumber.c_str()));
	std::cout << std::fixed << std::setprecision(1) << newValue << "f" << std::endl;
	return ;
};

void ScalarConverter::convertToDouble(std::string szToNumber)
{
	double newValue;
	newValue = static_cast<double>(atof(szToNumber.c_str()));
	std::cout << std::fixed << std::setprecision(1) << newValue << std::endl;
	return ;
};


void ScalarConverter::convert(std::string szToNumber)
{
	std::string newValue;
	newValue = handleError(szToNumber);

	std::cout << "char:\t";
	convertToChar(newValue);
	std::cout << "int:\t";
	convertToInt(newValue);
	std::cout << "float:\t";
	convertToFloat(newValue);
	std::cout << "double:\t";
	convertToDouble(newValue);
};
