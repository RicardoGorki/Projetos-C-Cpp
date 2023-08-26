#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>

struct Date {
    int year;
    int month;
    int day;
};
	bool isNumeric(const std::string &str);
	void displayError(const std::string &input);
	int verifyFormat(const std::string &input);
	int checkStructure(const std::string &input, const std::vector<std::string> &data);
	int isDateInRange(const Date& date, const Date& rangeStart, const Date& rangeEnd);
	int checkQuantity(float quantity);
	void displayFormat(int inputYear, int inputMonth, int inputDay, float inputQuantity, const std::vector<std::string> data);


#endif
