#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>
#include <stdbool.h>

/**
 * _printf - prints to the standard output
 * @format: the first arg
 * Return: 0
 */
int _printf(const char *format, ...)
{
        int i, j, intout, count = 0;
        unsigned int my_integer;
        char next_char, cc, buffer[12];
        char *string;
        bool isUppercase;
        va_list arg;

        if (*format == '\0' || (format[0] == '%' && format[1] == '\0'))
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
                                        return (-1);
                                for (j = 0; string[j] != '\0'; j++)
                                {
                                        _putchar(string[j]);
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
                        else if (format[i + 1] == 'X' || format[i + 1] == 'x')
                        {
                                my_integer = va_arg(arg, unsigned int);
                                isUppercase = (format[i + 1] == 'X');
                                hexadec(my_integer, &count, isUppercase);
                                i++;
                        }
                        else if (next_char == 'u')
                        {
                            my_integer = va_arg(arg, unsigned int);
                            unsign_Only(my_integer, &count);
                            i++;
                        }
                        else if (next_char == 'o')
                        {
                            intout = va_arg(arg, int);
                            octconversion(intout, &count);
                            i++;
                        }
                        else if (next_char == '%')
                        {
                                putchar('%');
                                i++;
                                count++;
                        }
                        else if (format[i + 1] == 'b')
                        {
                                my_integer = va_arg(arg, unsigned int);
                                handle_b(my_integer, &count);
                                i++;
                        }
                        else if (next_char == 'd' || next_char == 'i')
                        {
                                intout = va_arg(arg, int);
                                sprintf(buffer, "%d", intout);
                                count += write(1, buffer, strlen(buffer));
                                i++;
                        }
                }
                else
                {
                        putchar(format[i]);
                        count++;
                }
                if (format[i] == '\n')
                {
                        next_char = format[i + 1];
                        if (next_char == 'n')
                        {
                                putchar('\n');
                                i++;
                                count++;
                        }
                }
        }
        va_end(arg);
        return (count);
}
