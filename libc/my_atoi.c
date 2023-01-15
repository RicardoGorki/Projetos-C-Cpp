#include "libc.h"

static int	my_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\b')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	my_atoi(const char *str)
{
	int	res;
	int	i;
	int	signal;

	res = 0;
	i = 0;
	signal = 1;
	while (str[i] && my_isspace(str[i]))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			signal *= (-1);
		i++;
	}
	while (str && my_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	return (signal * res);
}
