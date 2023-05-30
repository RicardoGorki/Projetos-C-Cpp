#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contructor called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Destructor called" << std::endl;
}

std::string Contact::getFirstName()
{
	return (this->_first_name);
}

void Contact::setFirstName(std::string first_name)
{
	this->_first_name = first_name;
}

std::string Contact::getLastName()
{
	return (this->_last_name);
}

void Contact::setLastName(std::string last_name)
{
	this->_last_name = last_name;
}

std::string Contact::getNickName()
{
	return (this->_nick_name);
}

void Contact::setNickName(std::string nick_name)
{
	this->_nick_name = nick_name;
}

std::string Contact::getPhoneNumber()
{
	return (this->_phone_number);
}

void Contact::setPhoneNumber(std::string phone_number)
{
	this->_phone_number = phone_number;
}

std::string Contact::getDarkestSecret()
{
	return (this->_darkest_secret);
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}
