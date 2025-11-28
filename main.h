#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*main _printf function*/
int _printf(const char *format, ...);
/*character functions*/
int print_char(int c);
int print_str(char *str);
/*integer functions*/
int print_digit(int n);

#endif
