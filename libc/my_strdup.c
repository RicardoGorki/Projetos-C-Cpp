#include "libc.h"

char	*my_strdup(const char *s1)
{
	int		len;
	int		temp_len;
	char	*temp_s1;

	temp_s1 = (char *) s1;
	len = 0;
	temp_len = my_strlen(s1);
	temp_s1 = malloc(temp_len + 1);
	if (!temp_s1)
		return (NULL);
	while (s1[len])
	{
		temp_s1[len] = s1[len];
		len++;
	}
	temp_s1[len] = '\0';
	return (temp_s1);
}
