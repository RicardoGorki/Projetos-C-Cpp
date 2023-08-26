#include "BitcoinExchange.hpp"

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

int checkStructure(const std::string &input)
{
	std::istringstream stream(input);
	int year, month, day;
	float quantity;
	char dashFirst, dashSecond, delimiter, spaceFirst, spaceSecond;

	stream >> year >> dashFirst >> month >> dashSecond >> day >> spaceFirst >> delimiter >> spaceSecond >> quantity;
	if (stream.fail() || spaceFirst != 32 || spaceSecond != 32 || dashFirst != '-' || dashSecond != '-' || !year || !month || !day || delimiter != '|' || !quantity)
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

	displayFormat(year, month, day, quantity);

	return 0;
}
