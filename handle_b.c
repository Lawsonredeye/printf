#include "main.h"
#include <stdio.h>

/**
 * handle_b -  unsigned int argument is converted to binary
 * @my_integer: integer argument
 * @count: keep count of the number of character
 * Return: void
 */
void handle_b(int my_integer, int *count)
{
	int b;

	if (my_integer == 0 || my_integer == 1)
	{
		putchar(my_integer + '0');
		(*count)++;
	}
	else if (my_integer >= 2)
	{
		handle_b(my_integer / 2, count);
		b = my_integer % 2;
		putchar(b + '0');
		(*count)++;
	}
}
