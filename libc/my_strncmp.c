#include "libc.h"

int	my_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *) s1;
	temp_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (*temp_s1 != *temp_s2)
			return (*temp_s1 - *temp_s2);
		if (*temp_s1 == 0)
			return (0);
		temp_s1++;
		temp_s2++;
		n--;
	}
	return (0);
}
