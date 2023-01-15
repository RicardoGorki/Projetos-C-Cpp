#include "libc.h"

size_t	my_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	i = 0;
	ldst = my_strlen(dst);
	lsrc = my_strlen(src);
	if (dstsize == 0)
		return (lsrc);
	if (dstsize < ldst)
		return (lsrc + dstsize);
	while (src[i] && ldst + i < dstsize - 1)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	if (ldst < dstsize)
		dst[ldst + i] = '\0';
	return (lsrc + ldst);
}
