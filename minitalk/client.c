#include "../libc/libc.h"
#include <signal.h>

void	signal_handler(int signal)
{
	(void)signal;
}

void	my_char_to_bin(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	pid_t	pid;

	pid = my_atoi(argv[1]);
	i = 0;
	if (argc < 2)
		return (0);
	len = my_strlen(argv[2]);
	while (i < len)
		my_char_to_bin(argv[2][i++], pid);
	usleep(1000);
	return (0);
}
