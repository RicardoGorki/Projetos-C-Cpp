#include "my_printf.h"

int	my_putnbr_int(int nbr)
{
	long int	aux;

	aux = nbr;
	if (aux < 0)
	{
		my_putchar('-');
		aux *= -1;
	}
	if (aux > 9)
	{
		my_putnbr_int(aux / 10);
		my_putnbr_int(aux % 10);
	}
	if (aux < 10)
	{
		my_putchar(aux + '0');
	}
	return (my_count_int(nbr));
}
