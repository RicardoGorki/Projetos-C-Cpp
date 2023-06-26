#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:
	Contact	_contact[8];
	int		_count_contact;

public:
	PhoneBook(void);
	~PhoneBook(void);
	int		add_contact(int index);
	void	search_contact();
	void	body_contact(int i);
	void	index_contact(int i);
	std::string  format_contact(std::string get_name);
};
#endif
