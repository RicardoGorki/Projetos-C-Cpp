#include "BitcoinExchange.hpp"

void displayError(const std::string &input)
{
	std::cout << "Error: bad input => " << input << std::endl;
}

int verifyFormat(const std::string &input)
{
	if (input.length() < 14)
	{
		displayError(input);
		return (0);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (((i < 4) || (i > 4 && i < 7)  || (i > 7 && i < 10 ) ) && !isdigit(input[i]))
		{
			displayError(input);
			return (0);
		}
		if ((i == 4 || i == 7) && input[i] != '-')
		{
			displayError(input);
			return (0);
		}
		if (((i == 10) || (i == 12)) && input[i] != ' ')
		{
			displayError(input);
			return (0);
		}
		if ((i == 11) && input[i] != '|')
		{
			displayError(input);
			return (0);
		}
		if ((i == 13) && ( input[i] != '-' && input[i] != '+' && !isdigit(input[i]) ))
		{
			displayError(input);
			return (0);
		}
	}
	if (!isdigit(input[input.length() - 1]))
	{
			displayError(input);
			return (0);
	}
	return (1);
}

int isDateInRange(const Date &date, const Date &rangeStart, const Date &rangeEnd)
{
	if (date.year < rangeStart.year || date.year > rangeEnd.year)
		return 1;
	if (date.month < rangeStart.month || date.month > rangeEnd.month)
		return 1;
	if (date.day < rangeStart.day || date.day > rangeEnd.day)
		return 1;
	return 0;
}

int checkQuantity(float quantity)
{
	if (quantity < 0.1)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (quantity > 999.99)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (1);
	}
	return (0);
}

void displayFormat(int year, int month, int day, float quantity)
{
	float value = 1;

	std::cout << year << "-";
	if (month < 10)
		std::cout << "0";
	std::cout << month << "-";
	if (day < 10)
		std::cout << "0";
	std::cout << day << " => " << quantity
			  << " = " << value << std::endl;
}

bool isNumeric(const std::string &str)
{
	int count = 0;
	for (size_t i = 13; i < str.length(); ++i)
	{
		if (str[13] == '-' || str[13] == '+')
			i++;
		if (str[i] == '.')
			count++;
		if ((!isdigit(str[i]) && str[i] != '.') && count < 2)
			return false;
	}
	return true;
}

int checkStructure(const std::string &input)
{
	std::istringstream stream(input);
	int year, month, day;
	float quantity;
	char dashFirst, dashSecond, delimiter;

	stream >> year >> dashFirst >> month >> dashSecond >> day >> delimiter >> quantity;
	if (stream.fail() ||  dashFirst != '-' || dashSecond != '-' || !year || !month || !day || delimiter != '|' || !quantity)
	{
		std::cout << "Error: bad input => " << input << std::endl;
		return 1;
	}

	Date dateToCheck = {year, month, day};
	Date rangeStart = {1900, 1, 1};
	Date rangeEnd = {2023, 12, 31};
	if (isDateInRange(dateToCheck, rangeStart, rangeEnd))
	{
		std::cout << "Error: bad range date " << year << "-" << month << "-" << day << std::endl;
		return 1;
	}

	if (checkQuantity(quantity))
		return (1);

	if (!isNumeric(input))
	{
		std::cout << "Error: bad input => " << input << std::endl;
		return (1);
	}

	displayFormat(year, month, day, quantity);

	return 0;
}
