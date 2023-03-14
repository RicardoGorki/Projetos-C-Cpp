#include "my_printf.h"

int	my_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		my_putchar(str[i]);
		i++;
	}
	return (i);
}
