#include "main.h"
#include <stdio.h>

/**
 * fine_print - call write as little as possible.
 * @mychar: char data type arg
 * @myfile: buffer file
 * Return: void
 */
void fine_print(char mychar, FILE* myfile)
{
    static char buffer[1024];
    static int count = 0;

    buffer[count++] = mychar;

    if (count == 1024 || mychar == '\0')
    {
        fwrite(buffer, sizeof(char), count, myfile);
        count = 0;
    }
}
