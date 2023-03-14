#include "my_printf.h"

static int	my_printf_args(va_list vlist, const char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += my_putchar(va_arg(vlist, int));
	else if (str == 's')
		count += my_putstr(va_arg(vlist, const char *));
	else if (str == 'p')
	{
		count += my_putstr("0x");
		count += my_pointer(va_arg(vlist, unsigned long int));
	}
	else if (str == 'd' || str == 'i')
		count += my_putnbr_int(va_arg(vlist, int));
	else if (str == 'u')
		count += my_putnbr_unsigned(va_arg(vlist, unsigned int));
	else if (str == 'x')
		count += my_putnbr_hex_lower(va_arg(vlist, unsigned int));
	else if (str == 'X')
		count += my_putnbr_hex_upper(va_arg(vlist, unsigned int));
	else if (str == '%')
		count += my_putchar('%');
	return (count);
}

int	my_printf(const char *str, ...)
{
	va_list	vlist;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(vlist, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += my_printf_args(vlist, str[i + 1]);
			i++;
		}
		else
		{
			count += my_putchar(str[i]);
		}
		i++;
	}
	va_end(vlist);
	return (count);
}
