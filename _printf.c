#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    int i, j;
    char next_char;
    char* string;
    char cc, p;
    va_list arg;

    va_start(arg, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            next_char = format[i + 1];
            if (next_char == 's')
            {
               string = va_arg(arg, char *);
               for (j = 0; string[j] != '\0'; j++)
               {
                   putchar(string[j]);
               }
               i++;
            }
            else if (next_char == 'c')
            {
                cc = va_arg(arg, int);
                putchar(cc);
                i++;
            }
            else if (next_char == '%')
            {
                putchar('%');
                i++;
            }
        }
        else
            putchar(format[i]);
    }
    va_end(arg);
    return (0);
}
int main(void)
{
    _printf("%%");
}

