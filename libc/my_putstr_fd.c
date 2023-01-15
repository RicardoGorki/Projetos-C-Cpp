#include "libc.h"

void	my_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
		my_putchar_fd(s[i++], fd);
}
