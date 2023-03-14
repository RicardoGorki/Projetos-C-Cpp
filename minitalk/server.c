#include "../libc/libc.h"
#include <signal.h>

char	*g_byte;

void	my_dec_to_char(char *byte)
{
	int	dec;
	int	base;
	int	i;

	dec = 0;
	base = 1;
	i = 7;
	while (i >= 0)
	{
		dec += (byte[i] - 48) * base;
		base *= 2;
		i--;
	}
	my_putchar_fd(dec, 1);
}

void	signal_handler(int signal, siginfo_t *sa_info, void *test)
{
	(void)test;
	(void)sa_info;
	if (signal == SIGUSR1)
		g_byte = my_strjoin(g_byte, "1");
	if (signal == SIGUSR2)
		g_byte = my_strjoin(g_byte, "0");
	if (my_strlen(g_byte) == 8)
	{
		my_dec_to_char(g_byte);
		my_bzero(g_byte, 8);
	}
}

int	main(void)
{
	struct sigaction	s_sa;

	my_putstr_fd(my_itoa(getpid()), 1);
	my_putchar_fd('\n', 1);
	s_sa.sa_sigaction = &signal_handler;
	s_sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sa, 0);
	sigaction(SIGUSR2, &s_sa, 0);
	while (1)
		pause();
	return (0);
}
