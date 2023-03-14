#include "my_printf.h"

int	my_putnbr_hex_lower(unsigned int nbr)
{
	char	*str;

	str = "0123456789abcdef";
	if (nbr > 15)
	{
		my_putnbr_hex_lower(nbr / 16);
		my_putnbr_hex_lower(nbr % 16);
	}
	if (nbr < 16)
	{
		my_putchar(str[nbr]);
	}
	return (my_count_hex(nbr));
}
