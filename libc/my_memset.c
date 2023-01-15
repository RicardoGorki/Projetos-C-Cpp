#include "libc.h"

void	*my_memset(void *b, int c, size_t len)
{
	char			*temp;
	unsigned int	i;

	temp = (char *)b;
	i = 0;
	while (i < len)
	{
		temp[i] = (unsigned char) c;
		i++;
	}
	return (temp);
}
