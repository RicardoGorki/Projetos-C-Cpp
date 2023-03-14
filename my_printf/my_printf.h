#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	my_printf(const char *str, ...);
int	my_putchar(const char c);
int	my_putstr(const char *str);
int	my_pointer(unsigned long nbr);
int	my_count_int(int nbr);
int	my_putnbr_int(int nbr);
int	my_count_hex(unsigned int nbr);
int	my_count_pointer(unsigned long nbr);
int	my_count_unsigned(unsigned int nbr);
int	my_putnbr_unsigned(unsigned int nbr);
int	my_putnbr_hex_lower(unsigned int nbr);
int	my_putnbr_hex_upper(unsigned int nbr);

#endif
