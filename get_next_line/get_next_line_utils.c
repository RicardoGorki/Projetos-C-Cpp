#include "get_next_line.h"

size_t	my_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*my_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*temp_s;

	i = 0;
	len = my_strlen(s1);
	if (!s1)
		return (NULL);
	temp_s = malloc(len + 1);
	if (!temp_s)
		return (NULL);
	while (s1[i])
	{
		temp_s[i] = s1[i];
		i++;
	}
	temp_s[i] = '\0';
	return (temp_s);
}

char	*my_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*my_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp_s;
	int		len;

	i = 0;
	j = 0;
	if (!s1)
		s1 = my_strdup("");
	len = my_strlen(s1) + my_strlen(s2);
	temp_s = malloc(len + 1);
	if (!temp_s)
		return (NULL);
	while (s1[i])
	{
		temp_s[i] = s1[i];
		i++;
	}
	while (s2[j])
		temp_s[i++] = s2[j++];
	temp_s[i] = '\0';
	free(s1);
	return (temp_s);
}

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
		temp_s[i++] = s[start++];
	temp_s[i] = '\0';
	return (temp_s);
}
