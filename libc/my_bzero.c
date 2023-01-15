#include "libc.h"

void	my_bzero(void *s, size_t n)
{
	char			*temp;
	size_t			i;

	i = 0;
	temp = (char *)s;
	while (n > 0)
	{
		temp[i] = '\0';
		n--;
		i++;
	}
}
