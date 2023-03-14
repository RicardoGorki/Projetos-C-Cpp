#include "my_printf.h"

int	my_count_int(int nbr)
{
	int			count;
	long int	aux;

	count = 0;
	aux = nbr;
	if (aux < 0)
	{
		aux *= -1;
		count++;
	}
	while (aux > 9)
	{
		aux = (aux / 10);
		count++;
	}
	count++;
	return (count);
}
