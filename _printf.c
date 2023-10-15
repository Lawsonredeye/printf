#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function that prints
 * to the standard output
 * @format: the first arg
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0;
	char next_char;
	char *string;
	char cc;
	va_list arg;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			next_char = format[i + 1];
			if (next_char == 's')
			{
				string = va_arg(arg, char *);
				if (string == NULL)
				{
					return (-1);
				}
				for (j = 0; string[j] != '\0'; j++)
				{
					putchar(string[j]);
					count++;
				}
				i++;
			}
			else if (next_char == 'c')
			{
				cc = va_arg(arg, int);
				putchar(cc);
				i++;
				count++;
			}
			else if (next_char == '%')
			{
				putchar('%');
				i++;
				count++;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}
	va_end(arg);
	return (count);
}
