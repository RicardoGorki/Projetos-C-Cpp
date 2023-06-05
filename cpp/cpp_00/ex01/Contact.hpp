#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
class Contact {

private:

	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _phone_number;
	std::string _darkest_secret;

public:

	Contact(void);
	~Contact(void);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void setFirstName(std::string first_name);
	void setLastName(std::string last_name);
	void setNickName(std::string nick_name);
	void setPhoneNumber(std::string phone_number);
	void setDarkestSecret(std::string darkest_secret);

};

#endif
