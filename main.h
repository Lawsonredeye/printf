#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
int _printf(const char *format, ...);
void handle_b(int my_integer, int *count);
void hexadec(int hexa, int *count, bool isUppercase);
void octconversion(int octnum, int *count);
void unsign_Only(unsigned int nums, int *count);
int _putchar(char c);
#endif
