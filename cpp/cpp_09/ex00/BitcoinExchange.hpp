#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

struct Date {
    int year;
    int month;
    int day;
};

	std::string getOnlyData(const std::string &input);
	std::string trim(const std::string &input);
	int checkDate(const std::string &input);
	int isDateInRange(const Date& date, const Date& rangeStart, const Date& rangeEnd);

#endif
