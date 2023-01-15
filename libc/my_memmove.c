#include "libc.h"

void	*my_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*temp_dst;
	const char		*temp_src;

	temp_dst = (char *) dst;
	temp_src = (char *) src;
	i = 0;
	if (!temp_dst && !temp_src)
		return (NULL);
	if (temp_dst > temp_src)
	{
		while (len-- > 0)
			temp_dst[len] = temp_src[len];
	}
	else
	{
		while (i < len)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (temp_dst);
}
