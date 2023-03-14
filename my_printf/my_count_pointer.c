#include "my_printf.h"

int	my_count_pointer(unsigned long nbr)
{
	int	count;

	count = 0;
	while (nbr > 15)
	{
		nbr = (nbr / 16);
		count++;
	}
	count++;
	return (count);
}
