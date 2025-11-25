The _printf Projet 

## Authors

- **Jason Jean Louis** - *Developer*  
  GitHub: https://github.com/ToujoursPareil8/holbertonschool-printf

- **Sylvie Costa** - *Co-developer*  
  GitHub: https://github.com/Leyvsi/holbertonschool-printf

The _printf function is a simplified recreation of the standard printf function from the C library.
It formats and prints data to the standard output according to a format string.
This implementation supports a limited set of conversion specifiers.

The goal of this project is to understand:
howvariadic functions work (va_list, va_start, va_arg, va_end);
how to parse and process a format string;
how to print characters, strings and integers manually;
how recursion can be used to print numbers.

%c : Prints a single character
%s : Prints a string of characters
%d : Prints a signed integer
%i : Prints a signed integer
%% : Prints the % character

Prototype : int _printf(char *format, ...);

@_printf : Iterates through the format string,
when encountering a % character, checks the next character to determine the required conversion,
retrieves arguments using va_list,
calls helper functions to print characters, strings, or integers,
returns the total number of printed characters,

@print_char :prints a single character using write.
@print_str : prints a null-terminated string character by character.
@print_digit : prints an integer recursively,
handles negative numbers by printing - and converting the value to positive before recursion.

Main.h :
int print_char(char c);
int print_str(char *str);
int print_digit(int n);
int _printf(char *format, ...);

Compilation : gcc -Wall -Wextra -Werror -pedantic *.c -o printf

Return value : returns the total number of characters printed, 
returns -1 if format is NULL.


