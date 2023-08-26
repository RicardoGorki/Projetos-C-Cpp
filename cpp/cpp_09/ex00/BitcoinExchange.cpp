#include "BitcoinExchange.hpp"

std::string trim(const std::string &str)
{
	size_t firstNonSpace = str.find_first_not_of(" \t\r\n");
	size_t lastNonSpace = str.find_last_not_of(" \t\r\n");

	if (firstNonSpace == std::string::npos)
		return "";
	return (str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1));
}

std::string getOnlyData(const std::string &input)
{
	std::istringstream stream(input);
	std::string value;
	std::string onlyData;

	std::getline(stream, value, '|');
	std::istringstream streamValue(value);
	onlyData = trim(value);
	std::cout << onlyData << std::endl;
	return (onlyData);
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

int checkDate(const std::string &input)
{
	std::string dateStr = input;
	int year;
	int month;
	int day;

	std::istringstream dateStream(dateStr);
	char dash;

	dateStream >> year >> dash >> month >> dash >> day;

	std::cout << "Ano: " << year << ", Mês: " << month << ", Dia: " << day << std::endl;
	Date dateToCheck = {year, month, day};
	Date rangeStart = {1900, 1, 1};
	Date rangeEnd = {2023, 12, 31};

	if (isDateInRange(dateToCheck, rangeStart, rangeEnd))
	{
		std::cout << "Error: put a more recent data " << std::endl;
		return 1;
	}
	return (0);
}
