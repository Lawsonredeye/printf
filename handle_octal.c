#include "main.h"
#include <stdio.h>

/**
 * octconversion - used to calculate octal values
 * @octnums: formal parameter being passed
 * @count: pointer to an int for counting printed characters
 * Return: Nothing
 */
void octconversion(int octnum, int *count)
{
	char myoctal[] = "01234567";

	if (octnum > 0)
	{
		octconversion(octnum / 8, count);
		putchar(myoctal[octnum % 8]);
		(*count)++;
	}
}
