#include "libc.h"

char	*my_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*temp_s;

	i = 0;
	if (!s)
		return (NULL);
	temp_s = malloc(my_strlen(s) + 1);
	if (!temp_s)
		return (NULL);
	while (s[i])
	{
		temp_s[i] = f(i, s[i]);
		i++;
	}
	temp_s[i] = '\0';
	return (temp_s);
}
