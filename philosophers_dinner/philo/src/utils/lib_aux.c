#include "../philosofers.h"

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
		return (1);
	else
		return (0);
}

static int	my_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\b')
		return (1);
	else
		return (0);
}

static void	atoi_errors(unsigned long res)
{
	if (res == 0)
		error_msg("Only positive numbers");
	if ((res) > 2147483647)
		error_msg("Only int limits\n");
}

unsigned long	atoi_philo(const char *str)
{
	unsigned long	res;
	int				i;

	res = 0;
	i = 0;
	while (str[i] != '\0' && my_isspace(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (!my_isdigit(str[i]))
			error_msg("Only digits\n");
		res = res * 10 + str[i] - '0';
		i++;
	}
	atoi_errors(res);
	return (res);
}
