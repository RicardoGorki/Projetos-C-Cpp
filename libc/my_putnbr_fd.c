#include "libc.h"

void	my_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			my_putstr_fd("-2147483648", fd);
			return ;
		}
		my_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		my_putnbr_fd(n / 10, fd);
		my_putnbr_fd(n % 10, fd);
	}
	if (n < 10)
	{
		my_putchar_fd(n + '0', fd);
	}
}
