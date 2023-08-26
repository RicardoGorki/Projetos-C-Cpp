#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>

struct Date {
    int year;
    int month;
    int day;
};

	std::string getOnlyData(const std::string &input);
	std::string trim(const std::string &input);
	int checkStructure(const std::string &input);
	int isDateInRange(const Date& date, const Date& rangeStart, const Date& rangeEnd);
	int checkQuantity(float quantity);

#endif
