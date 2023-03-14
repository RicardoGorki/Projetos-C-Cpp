#include "my_printf.h"

int	my_pointer(unsigned long nbr)
{
	char	*str;

	str = "0123456789abcdef";
	if (nbr > 15)
	{
		my_pointer(nbr / 16);
		my_pointer(nbr % 16);
	}
	if (nbr < 16)
	{
		my_putchar(str[nbr]);
	}
	return (my_count_pointer(nbr));
}
