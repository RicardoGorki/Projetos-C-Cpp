#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char *str;
	int fd;

	fd = open("foo.txt", O_RDONLY);

	str = get_next_line(fd);
	while (*str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (0);
}
