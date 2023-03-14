#include "my_printf.h"

int	my_count_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	while (nbr > 9)
	{
		nbr = (nbr / 10);
		count++;
	}
	count++;
	return (count);
}
