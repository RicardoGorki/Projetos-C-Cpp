#include "libc.h"

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp_s;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= my_strlen(s))
		return (my_strdup(""));
	if (len >= my_strlen(s))
		len = my_strlen(s);
	temp_s = malloc(len + 1);
	if (temp_s == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		temp_s[i] = s[start];
		i++;
		start++;
	}
	temp_s[i] = '\0';
	return (temp_s);
}
