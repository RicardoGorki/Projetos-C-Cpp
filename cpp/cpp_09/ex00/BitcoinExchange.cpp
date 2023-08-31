#include "BitcoinExchange.hpp"

void displayError(const std::string &input)
{
	std::cerr << "Error: bad input => " << input << std::endl;
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
		if (((i < 4) || (i > 4 && i < 7) || (i > 7 && i < 10)) && !isdigit(input[i]))
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
		if ((i == 13) && (input[i] != '-' && input[i] != '+' && !isdigit(input[i])))
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
		std::cerr << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (quantity > 999.99)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (1);
	}
	return (0);
}

size_t localizeLowerDate(const std::vector<std::string> data, size_t save_last, int inputMonth, int inputDay)
{
	for (size_t i = save_last; i < data.size(); i++)
	{
		std::istringstream stream(data[i]);
		int dataYear, dataMonth, dataDay;
		char dashFirst, dashSecond;

		stream >> dataYear >> dashFirst >> dataMonth >> dashSecond >> dataDay;
		if (dataMonth != inputMonth)
			save_last = i;
		if (dataMonth == inputMonth && dataDay < inputDay)
			save_last = i;
		if (dataDay > inputDay)
			break;
	}
	return (save_last);
}

void reduceData(int prevYear, int prevMonth, int prevDay,
				int inputYear, int inputMonth, int inputDay, float inputQuantity,
				const std::vector<std::string> data, size_t save_last, size_t i)
{
	if (!prevYear)
	{
		std::istringstream stream(data[data.size() - 1]);
		int dataYear, dataMonth, dataDay;
		float value;
		char dashFirst, dashSecond, delimiter;
		stream >> dataYear >> dashFirst >> dataMonth >> dashSecond >> dataDay >> delimiter >> value;
		value *= inputQuantity;
		std::cout << inputYear << "-";
		if (inputMonth < 10)
			std::cout << "0";
		std::cout << inputMonth << "-";
		if (inputDay < 10)
			std::cout << "0";
		std::cout << inputDay;
		std::cout << " => " << inputQuantity << " = ";
		std::cout << value << std::endl;
	}
	else if (!prevMonth)
	{
		save_last = localizeLowerDate(data, save_last, inputMonth, inputDay);
		std::istringstream stream(data[save_last]);
		int dataYear, dataMonth, dataDay;
		float value;
		char dashFirst, dashSecond, delimiter;
		stream >> dataYear >> dashFirst >> dataMonth >> dashSecond >> dataDay >> delimiter >> value;
		value *= inputQuantity;
		std::cout << inputYear << "-";
		if (inputMonth < 10)
			std::cout << "0";
		std::cout << inputMonth << "-";
		if (inputDay < 10)
			std::cout << "0";
		std::cout << inputDay;
		std::cout << " => " << inputQuantity << " = ";
		std::cout << value << std::endl;
	}
	else if (!prevDay)
	{
		save_last = localizeLowerDate(data, save_last, inputMonth, inputDay);
		std::istringstream stream(data[save_last]);
		int dataYear, dataMonth, dataDay;
		float value;
		char dashFirst, dashSecond, delimiter;
		stream >> dataYear >> dashFirst >> dataMonth >> dashSecond >> dataDay >> delimiter >> value;
		value *= inputQuantity;
		std::cout << inputYear << "-";
		if (inputMonth < 10)
			std::cout << "0";
		std::cout << inputMonth << "-";
		if (inputDay < 10)
			std::cout << "0";
		std::cout << inputDay;
		std::cout << " => " << inputQuantity << " = ";
		std::cout << std::fixed << std::setprecision(2) <<  value << std::endl;
	}
	else
	{
		std::istringstream stream(data[i]);
		int dataYear, dataMonth, dataDay;
		float value;
		char dashFirst, dashSecond, delimiter;
		stream >> dataYear >> dashFirst >> dataMonth >> dashSecond >> dataDay >> delimiter >> value;
		value *= inputQuantity;
		std::cout << inputYear << "-";
		if (inputMonth < 10)
			std::cout << "0";
		std::cout << inputMonth << "-";
		if (inputDay < 10)
			std::cout << "0";
		std::cout << inputDay;
		std::cout << " => " << inputQuantity << " = ";
		std::cout << value << std::endl;
	}
}

void displayFormat(int inputYear, int inputMonth, int inputDay, float inputQuantity, const std::vector<std::string> data)
{
	size_t i;
	int prevYear = 0, prevMonth = 0, prevDay = 0;
	size_t save_last;
	for (i = 0; i < data.size(); ++i)
	{
		std::istringstream stream(data[i]);
		int dataYear, dataMonth, dataDay;
		char dashFirst, dashSecond;

		stream >> dataYear >> dashFirst >> dataMonth >> dashSecond >> dataDay;
		if (dataYear == inputYear)
		{
			if (!prevYear)
			{
				prevYear = inputYear;
				save_last = i;
			}
			if (dataMonth == inputMonth)
			{
				if (!prevMonth)
				{
					prevMonth = inputMonth;
					save_last = i;
				}
				if (dataDay == inputDay)
				{
					prevDay = inputDay;
					break;
				}
			}
		}
	}

	reduceData(prevYear, prevMonth, prevDay,
			   inputYear, inputMonth, inputDay,
			   inputQuantity, data, save_last, i);
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

int checkStructure(const std::string &input, const std::vector<std::string> &data)
{
	std::istringstream stream(input);
	int year, month, day;
	float quantity;
	char dashFirst, dashSecond, delimiter;

	stream >> year >> dashFirst >> month >> dashSecond >> day >> delimiter >> quantity;
	if (stream.fail() || dashFirst != '-' || dashSecond != '-' || !year || !month || !day || delimiter != '|' || !quantity)
	{
		displayError(input);
		return 1;
	}

	Date dateToCheck = {year, month, day};
	Date rangeStart = {2009, 1, 1};
	Date rangeEnd = {2023, 12, 31};
	if (isDateInRange(dateToCheck, rangeStart, rangeEnd))
	{
		std::cerr << "Error: bad range date " << year << "-" << month << "-" << day << std::endl;
		return 1;
	}

	if (checkQuantity(quantity))
		return (1);

	if (!isNumeric(input))
	{
		std::cerr << "Error: bad input => " << input << std::endl;
		return (1);
	}

	displayFormat(year, month, day, quantity, data);

	return 0;
}
