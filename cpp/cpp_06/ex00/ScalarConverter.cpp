#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};
ScalarConverter::~ScalarConverter(){};
ScalarConverter::ScalarConverter(ScalarConverter &other)
{
	(void)other;
};
ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	(void)other;
	return (*this);
};

void ScalarConverter::convertToChar(std::string szToNumber)
{
	if (szToNumber == "nan" || szToNumber == "+inf" || szToNumber == "-inf")
		std::cout << "impossible" << std::endl;
	char newChar;
	newChar = static_cast<char>(szToNumber[0]);
	if (newChar < 32 || newChar > 126)
		std::cout << "Non displayable" << std::endl;
	else if (newChar > 31 && newChar < 127)
		std::cout << "'" << newChar << "'" << std::endl;

	std::cout << "int:\t ";
	if (szToNumber == "nan" || szToNumber == "+inf" || szToNumber == "-inf")
		std::cout << "impossible" << std::endl;

	int newInt;
	newInt = static_cast<int>(newChar);
	std::cout << newInt << std::endl;

	std::cout << "float:\t ";
	float newFloat;
	newFloat = static_cast<float>(newChar);
	std::cout << std::fixed << std::setprecision(1) << newFloat << "f" << std::endl;

	std::cout << "double:\t ";
	double newDouble;
	newDouble = static_cast<double>(newChar);
	std::cout << std::fixed << std::setprecision(1) << newDouble << std::endl;
};

void ScalarConverter::convertToInt(std::string szToNumber)
{
	if (szToNumber == "nan" || szToNumber == "+inf" || szToNumber == "-inf")
		std::cout << "impossible" << std::endl;

	int newInt;
	newInt = static_cast<int>(atoi(szToNumber.c_str()));
	std::cout << newInt << std::endl;

	std::cout << "char:\t";
	if (szToNumber == "nan" || szToNumber == "+inf" || szToNumber == "-inf")
		std::cout << "impossible" << std::endl;

	char newChar;
	newChar = static_cast<char>(newInt);
	if (newChar < 32 || newChar > 126)
		std::cout << "Non displayable" << std::endl;
	else if (newChar > 31 && newChar < 127)
		std::cout << "'" << newChar << "'" << std::endl;

	std::cout << "float:\t ";
	float newFloat;
	newFloat = static_cast<float>(newInt);
	std::cout << std::fixed << std::setprecision(1) << newFloat << "f" << std::endl;
	std::cout << "double:\t ";
	double newDouble;
	newDouble = static_cast<double>(newInt);
	std::cout << std::fixed << std::setprecision(1) << newDouble << std::endl;
};

void ScalarConverter::convertToFloat(std::string szToNumber)
{
	float newFloat;
	newFloat = static_cast<float>(atof(szToNumber.c_str()));
	std::cout << std::fixed << std::setprecision(1) << newFloat << "f" << std::endl;

	std::cout << "char:\t";

	if (szToNumber == "nan" || szToNumber == "+inf" || szToNumber == "-inf")
		std::cout << "impossible" << std::endl;

	char newChar;
	newChar = static_cast<char>(newFloat);
	if (newChar < 32 || newChar > 126)
		std::cout << "Non displayable" << std::endl;
	else if (newChar > 31 && newChar < 127)
		std::cout << "'" << newChar << "'" << std::endl;

	std::cout << "int:\t ";

	if (szToNumber == "nan" || szToNumber == "+inf" || szToNumber == "-inf")
		std::cout << "impossible" << std::endl;

	int newInt;
	newInt = static_cast<int>(newFloat);
	std::cout << newInt << std::endl;

	std::cout << "double:\t ";
	double newDouble;
	newDouble = static_cast<double>(newFloat);
	std::cout << std::fixed << std::setprecision(1) << newDouble << std::endl;
};

void ScalarConverter::convertToDouble(std::string szToNumber)
{
	double newDouble;
	newDouble = static_cast<double>(atof(szToNumber.c_str()));
	std::cout << std::fixed << std::setprecision(1) << newDouble << std::endl;

	std::cout << "char:\t";

	if (szToNumber == "nan" || szToNumber == "+inf" || szToNumber == "-inf")
		std::cout << "impossible" << std::endl;

	char newChar;
	newChar = static_cast<char>(newDouble);
	if (newChar < 32 || newChar > 126)
		std::cout << "Non displayable" << std::endl;
	else if (newChar > 31 && newChar < 127)
		std::cout << "'" << newChar << "'" << std::endl;

	std::cout << "int:\t ";

	if (szToNumber == "nan" || szToNumber == "+inf" || szToNumber == "-inf")
		std::cout << "impossible" << std::endl;

	int newInt;
	newInt = static_cast<int>(newDouble);
	std::cout << newInt << std::endl;
	std::cout << "float:\t ";
	float newFloat;
	newFloat = static_cast<float>(newDouble);
	std::cout << std::fixed << std::setprecision(1) << newFloat << "f" << std::endl;
	return;
};

int ScalarConverter::identifyType(std::string szToNumber)
{
	if ((szToNumber == "nan") || (szToNumber == "+inf")
		|| (szToNumber == "inf") || (szToNumber == "-inf")
		|| (szToNumber == "nanf") || (szToNumber == "+inff")
		|| (szToNumber == "inff") || (szToNumber == "-inff"))
		return (0); // errors especiais
	if (szToNumber.length() == 1)
	{
		if ((szToNumber[0] > 31 && szToNumber[0] < 48) ||
			(szToNumber[0] > 57 && szToNumber[0] < 127))
			return (1); // char
	}
	if (szToNumber.length() == 1)
	{
		if (szToNumber[0] > 47 && szToNumber[0] < 58)
			return (2); // int
	}
	int count = 0;
	int countf = 0;
	int signal = 0;
	for (int i = 0; i < (int)szToNumber.length(); i++)
	{
		if (signal < 1 && (szToNumber[0] == '+' || szToNumber[0] == '-'))
		{
			signal++;
			i++;
		}
		if (szToNumber[i] == '.')
		{
			count++;
			if (count > 1)
				return (0);
		}
		if ((szToNumber[i] > 31 && szToNumber[i] < 46) || (szToNumber[i] == 47) || (szToNumber[i] > 57 && szToNumber[i] < 102) || (szToNumber[i] > 102))
			return (0);
		if (szToNumber[i] == 102)
			countf++;
	}
	if (countf > 1 || count > 1)
		return (0);
	if (countf == 1 && count == 1 && szToNumber[szToNumber.length() - 1] == 102)
		return (3);
	else if (countf == 1 && count == 1 && szToNumber[szToNumber.length() - 1] != 102)
		return (0);
	if (count == 1 && countf == 0)
		return (4);
	return (2);
}

void ScalarConverter::handleError(std::string szToNumber)
{
	if (szToNumber == "nan")
	{
		std::cout << "char:\t"
				  << "impossible" << std::endl;
		std::cout << "int:\t"
				  << "impossible" << std::endl;
		std::cout << "float:\t"
				  << "nanf" << std::endl;
		std::cout << "double:\t"
				  << "nan" << std::endl;
	}
	else if ((szToNumber == "+inf") || (szToNumber == "inf"))
	{
		std::cout << "char:\t"
				  << "impossible" << std::endl;
		std::cout << "int:\t"
				  << "impossible" << std::endl;
		std::cout << "float:\t"
				  << "inff" << std::endl;
		std::cout << "double:\t"
				  << "inf" << std::endl;
	}
	else if (szToNumber == "-inf")
	{
		std::cout << "char:\t"
				  << "impossible" << std::endl;
		std::cout << "int:\t"
				  << "impossible" << std::endl;
		std::cout << "float:\t"
				  << "-inff" << std::endl;
		std::cout << "double:\t"
				  << "-inf" << std::endl;
	}
	else if (szToNumber == "nanf")
	{
		std::cout << "char:\t"
				  << "impossible" << std::endl;
		std::cout << "int:\t"
				  << "impossible" << std::endl;
		std::cout << "float:\t"
				  << "nanf" << std::endl;
		std::cout << "double:\t"
				  << "nan" << std::endl;
	}
	else if ((szToNumber == "+inff") || (szToNumber == "inff"))
	{
		std::cout << "char:\t"
				  << "impossible" << std::endl;
		std::cout << "int:\t"
				  << "impossible" << std::endl;
		std::cout << "float:\t"
				  << "inff" << std::endl;
		std::cout << "double:\t"
				  << "inf" << std::endl;
	}
	else if (szToNumber == "-inff")
	{
		std::cout << "char:\t"
				  << "impossible" << std::endl;
		std::cout << "int:\t"
				  << "impossible" << std::endl;
		std::cout << "float:\t"
				  << "-inff" << std::endl;
		std::cout << "double:\t"
				  << "-inf" << std::endl;
	}
	else
	{
		std::cout << "Only numbers and pseudo literals" << std::endl;
	}
}

void ScalarConverter::convert(std::string szToNumber)
{
	int op;
	op = identifyType(szToNumber);

	switch (op)
	{
	case 0:
		handleError(szToNumber);
		break;
	case 1:
		std::cout << "char:\t";
		convertToChar(szToNumber);
		break;
	case 2:
		std::cout << "int:\t";
		convertToInt(szToNumber);
		break;
	case 3:
		std::cout << "float:\t";
		convertToFloat(szToNumber);
		break;
	case 4:
		std::cout << "double:\t";
		convertToDouble(szToNumber);
		break;
	default:
		break;
	}
};
