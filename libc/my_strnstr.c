#include "libc.h"

char	*my_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	if (len == 0 || *haystack == '\0')
		return (0);
	while (haystack[i] != '\0')
	{
		count = 0;
		if (haystack[i] == needle[count])
		{
			while (haystack[i + count] == needle[count] && i + count < len)
			{
				if (needle[count + 1] == '\0')
					return ((char *)&haystack[i]);
				count++;
			}
		}
		i++;
	}
	return (0);
}
