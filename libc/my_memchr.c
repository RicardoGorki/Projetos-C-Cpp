#include "libc.h"

void	*my_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp_s;

	temp_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (temp_s[i] == (unsigned char)c && i <= n)
			return (&temp_s[i]);
		i++;
	}
	return (0);
}
