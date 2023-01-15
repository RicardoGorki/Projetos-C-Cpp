#include "libc.h"

char	*my_strjoin(char const *s1, char const *s2)
{
	char	*temp_s1;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	temp_s1 = malloc(my_strlen(s1) + my_strlen(s2) + 1);
	if (!temp_s1)
		return (NULL);
	while (s1[i] != '\0')
	{
		temp_s1[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		temp_s1[i++] = s2[j++];
	}
	temp_s1[i] = '\0';
	return (temp_s1);
}
