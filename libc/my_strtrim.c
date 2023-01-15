#include "libc.h"

static int	my_setcmp(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*my_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		max_len;
	char	*temp_s;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	max_len = my_strlen(s1);
	while (s1[i] != '\0' && my_setcmp(s1[i], set))
		i++;
	while (max_len >= i && my_setcmp(s1[max_len - 1], set))
		max_len--;
	temp_s = malloc(max_len - i + 1);
	if (!temp_s)
		return (NULL);
	while (s1[i] != '\0' && i < max_len)
	{
		temp_s[j] = s1[i];
		j++;
		i++;
	}
	temp_s[j] = '\0';
	return (temp_s);
}
