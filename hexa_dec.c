#include "main.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * hexadec - find the hexadecimal of a value
 * @hexa: number variable
 * @count: keeps track of putchar
 * @isUppercase: knows if its x or X
 * Return: void
 */
void hexadec(int hexa, int *count, bool isUppercase)
{
	char hexLowerDigit[] = "0123456789abcdef";
	char hexUpperDigit[] = "0123456789ABCDEF";

	if (hexa > 0)
	{
		hexadec(hexa / 16, count, isUppercase);
		if (isUppercase)
		{
			putchar(hexUpperDigit[hexa % 16]);
			(*count)++;
		}
		else
		{
			putchar(hexLowerDigit[hexa % 16]);
			(*count)++;
		}
	}
}
