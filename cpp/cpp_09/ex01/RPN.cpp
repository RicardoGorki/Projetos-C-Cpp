#include "RPN.hpp"

int verifyContent(std::string content)
{
	for (size_t i = 0; i < content.length(); i++)
	{
		if ((!isdigit(content[i]) && (content[i] != '+' && content[i] != '-' && content[i] != '*' && content[i] != '/' && content[i] != ' ')))
			return (1);
	}
	return (0);
}

int result(int valueA, int valueB, unsigned char signal)
{
	int value = 0;
	if (signal == '+')
		value = valueA + valueB;
	else if (signal == '-')
		value = valueA - valueB;
	else if (signal == '*')
		value = valueA * valueB;
	else if (signal == '/')
		value = valueA / valueB;
	return (value);
}

void calculator(std::string content)
{
	std::stack<int> myStack;
	int value = 0;
	int valueA = 0;
	int valueB = 0;

	for (size_t i = 0; i < content.length(); i++)
	{
		if (isdigit(content[i]))
			myStack.push((content[i] - 48));
		if ((content[i] == '+' || content[i] == '-'
			|| content[i] == '*' || content[i] == '/')
			&& myStack.size() > 1)
		{
			valueA = myStack.top();
			myStack.pop();
			valueB = myStack.top();
			myStack.pop();
			myStack.push(result(valueB, valueA, content[i]));
			value = myStack.top();
		}
	}
	if (myStack.size() != 1)
	{
		std::cerr << "Error: operation illegal" << std::endl;
		return ;
	}
	std::cout << value << std::endl;
	return ;
}
