#include "main.h"

/**
 * unsign_Only - used to calculate unsigned int
 * @nums: formal parameter being passed
 * @count: pointer to an int for counting printed characters
 * Return: Nothing
 */
void unsign_Only(unsigned int nums, int *count)
{
	char numargs[11];
	int i;

	if (nums == 0)
	{
		_putchar('0');
		(*count)++;
	}
	else
	{
		for (i = 0; nums != 0; i++)
		{
			numargs[i] = (nums % 10) + '0';
			nums = nums / 10;
		}
		numargs[i] = '\0';
		for (i = i - 1; i >= 0; i++)
			_putchar(numargs[i]);
		(*count)++;
	}
}
