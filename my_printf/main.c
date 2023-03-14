#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "my_printf.h"

int	main(void)
{
	void	*ptr;
	int		value;
	char	*str;

	str = NULL;
	ptr = NULL;
	value = 42;
	ptr = &value;
	printf("	-| Char |-	\n");
	printf("Std-Char:\t\t");
	printf("\t - Len: |%i|", printf("Meu char: %c", 'a'));
	printf("\nFT-Char:\t\t\n");
	my_printf("\t - Len: |%i|", my_printf("Meu char: %c", 'a'));
	printf("\n\n	-| String |-	");
	printf("\nString:\t");
	printf("\t - Len: |%i|", printf("%s", "Lorem ipsum"));
	printf("\nFT-String:\t\t\n");
	my_printf("\t - Len: |%i|", my_printf("%s", "Lorem ipsum"));
	printf("\n\n	-| Pointer |-	");
	printf("\nStd-Ptr - NULL:\t");
	printf("\t - Len: |%i|", printf("%p", NULL));
	printf("\nStd-Ptr:\t");
	printf("\t - Len: |%i|", printf("%p", &ptr));
	printf("\n\n	-| Pointer FT |-	");
	printf("\nFT-Ptr - NULL:\t");
	my_printf("\t - Len: |%i|", my_printf("%p", NULL));
	printf("\nFT-Ptr:\t");
	my_printf("\t - Len: |%i|", my_printf("%p", &ptr));
	printf("\n\n	-| Decimal |-	");
	printf("\nStd-Decimal:\t");
	printf("\t - Len: |%i|", printf("%d", INT_MAX));
	printf("\nFT-Decimal:\t\t\n");
	my_printf("\t - Len: |%i|", my_printf("%d", INT_MAX));
	printf("\n\n	-| Integer |-	");
	printf("\nStd-Int:\t");
	printf("\t - Len: |%i|", printf("%i", INT_MIN));
	printf("\nFT-Int:\t\t\n");
	my_printf("\t - Len: |%i|", my_printf("%i", INT_MIN));
	printf("\n\n	-| Unsigned Int |-	");
	printf("\nStd-Unsiged: ");
	printf("\t - Len: |%i|", printf("%u", UINT_MAX));
	printf("\nFT-Unsigned:\t\t\n");
	my_printf("\t - Len: |%i|", my_printf("%u", UINT_MAX));
	printf("\n\n	-| Hexadecimal Lowercase |-	");
	printf("\nStd-Hex Lower:\t");
	printf("\t - Len: |%i|", printf("%x", 255));
	printf("\nFT-Hex Lower:\t\t\n");
	my_printf("\t - Len: |%i|", my_printf("%x", 255));
	printf("\n\n	-| Hexadecimal Uppercase |- ");
	printf("\nStd-Hex Upper:\t");
	printf("\t - Len: |%i|", printf("%X", 73914739));
	printf("\n\tFT-Hex Upper:");
	my_printf("\t - Len: |%i|", my_printf("%X", 73914739));
	printf("\n\n	-| Print Percent |-	");
	printf("\nStd-Percent:\t");
	printf("\t - Len: |%i|", printf("%%"));
	printf("\n\tFT-Percent:");
	my_printf("\t - Len: |%i|", my_printf("%%"));
	printf("\n\n");
	printf("\nSalada Mista\n");
	printf(" - Len:|%i|\n", printf("StrNull: |%s| - String: |%s| - Char: |%c| - Ptr: |%p| - Dec: |%d| - Int: |%i| - UInt: |%u| - HexL: |%x| - HexU: |%X| - %%", str, "Banana", 'A', NULL, INT_MAX, INT_MIN, UINT_MAX, 2022, 2022));
	printf("\n");
	my_printf(" - Len:|%i|", my_printf("StrNull: |%s| - String: |%s| - Char: |%c| - Ptr: |%p| - Dec: |%d| - Int: |%i| - UInt: |%u| - HexL: |%x| - HexU: |%X| - %%", str, "Banana", 'A', NULL, INT_MAX, INT_MIN, UINT_MAX, 2022, 2022));

	return (0);
}
