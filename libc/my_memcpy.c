#include "libc.h"

void	*my_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	size_t			i;

	i = 0;
	temp_src = (unsigned char *) src;
	temp_dst = (unsigned char *) dst;
	if (!temp_dst && !temp_src)
		return (NULL);
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (temp_dst);
}
