#include "get_next_line.h"

static char	*get_rest_of_line(char *s1)
{
	unsigned int	i;
	char			*temp_s;

	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\0')
	{
		free(s1);
		return (NULL);
	}
	if (s1[i] == '\n')
		i++;
	temp_s = my_substr(s1, i, my_strlen(s1) - i);
	free(s1);
	return (temp_s);
}

static char	*get_first_arg_line(char *s1)
{
	unsigned int	i;
	char 			*temp_s;

	i = 0;
	if (s1[i] == '\0')
		return (NULL);
	while(s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	temp_s = my_substr(s1, 0, i);
	return (temp_s);
}

static char	*get_current_line(int fd, char *line)
{
	int			 count_read;
	char		*buffer;

	count_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!line)
		line = my_strdup("\0");
	while (count_read > 0 && !my_strchr(line, '\n'))
	{
		count_read = read(fd, buffer, BUFFER_SIZE);
		if (count_read < 0)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[count_read] = '\0';
		line = my_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	buffer = get_current_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_first_arg_line(buffer);
	buffer = get_rest_of_line(buffer);

	return (line);
}
