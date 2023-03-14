#include "../push_swap.h"

int	my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	my_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	my_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\b')
		return (1);
	else
		return (0);
}

static void	atoi_errors(const char *str, long signal, long res, int *stack)
{
	int	i;

	i = my_strlen((char *)str);
	if (((i == 1 && str[0] == '-') || (i == 1 && str[0] == '+')))
		error_msg(stack, "Only digits\n");
	if ((signal * res) > 2147483647 || (signal * res < -2147483648))
		error_msg(stack, "Only int limits\n");
}

long int	atoi_ps(const char *str, int *stack)
{
	long	res;
	int		i;
	long	signal;

	res = 0;
	i = 0;
	signal = 1;
	while (str[i] != '\0' && my_isspace(str[i]))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			signal *= (-1);
		i++;
	}
	while (str[i] != '\0')
	{
		if (!my_isdigit(str[i]))
			error_msg(stack, "Only digits\n");
		res = res * 10 + str[i] - '0';
		i++;
	}
	atoi_errors(str, signal, res, stack);
	return (signal * res);
}
