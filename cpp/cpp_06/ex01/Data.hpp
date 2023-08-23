#ifndef DATA_HPP
# define DATA_HPP

class Data
{
private:
	Data();
	Data(Data &other);
	Data &operator=(Data &other);
	unsigned int _unValue;

public:
	Data(unsigned int unValue);
	~Data();
	unsigned int getValue();


};

#endif
