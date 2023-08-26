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
	bool isNumeric(const std::string &str);
	void displayError(const std::string &input);
	int verifyFormat(const std::string &input);
	int checkStructure(const std::string &input);
	int isDateInRange(const Date& date, const Date& rangeStart, const Date& rangeEnd);
	int checkQuantity(float quantity);

#endif
