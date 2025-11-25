#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/*main _printf function*/
int _printf(char *format, ...);
/*character functions*/
int print_char(int c);
int print_str(char *str);
/*integer functions*/
int print_digit(int n);
int print_int(va_list args);
int print_int_helper(int n);

#endif
