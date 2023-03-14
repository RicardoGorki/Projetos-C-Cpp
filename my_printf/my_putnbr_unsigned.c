#include "my_printf.h"

int	my_putnbr_unsigned(unsigned int nbr)
{
	if (nbr > 9)
	{
		my_putnbr_unsigned(nbr / 10);
		my_putnbr_unsigned(nbr % 10);
	}
	if (nbr < 10)
	{
		my_putchar(nbr + '0');
	}
	return (my_count_unsigned(nbr));
}
