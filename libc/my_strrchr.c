#include "libc.h"

char	*my_strrchr(const char *s, int c)
{
	char			*temp_s;
	unsigned int	max_len;
	unsigned int	i;

	temp_s = (char *) s;
	i = my_strlen(temp_s);
	max_len = my_strlen(temp_s);
	if (max_len > 0)
	{
		while (temp_s[i] != (char)c && i != 0)
			i--;
		if (temp_s[i] == (char) c)
			return (&temp_s[i]);
	}
	return (NULL);
}
