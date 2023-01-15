#include "libc.h"

char	*my_strchr(const char *s, int c)
{
	char			*temp_s;
	unsigned int	max_len;

	temp_s = (char *) s;
	max_len = my_strlen(temp_s);
	if (max_len > 0)
	{
		while (*temp_s != (char)c && *temp_s)
			temp_s++;
		if (*temp_s == (char)c)
			return (temp_s);
	}
	return (NULL);
}
