#ifndef DATA_HPP
# define DATA_HPP

class Data
{
private:
	Data();
	unsigned int _unValue;

public:
	Data(unsigned int unValue);
	~Data();
	unsigned int getValue();
	Data(Data &other);
	Data &operator=(Data &other);
};

#endif
