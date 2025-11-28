The _printf Projet 

## Authors

- **Jason Jean Louis** - *Developer*  
  GitHub: https://github.com/ToujoursPareil8/holbertonschool-printf

- **Sylvie Costa** - *Co-developer*  
  GitHub: https://github.com/Leyvsi/holbertonschool-printf

_printf is a simpler version of the C library printf function,
it prints text following the rules of a format string,
this version only supports a few basic format specifiers.

The goal of this project is to learn :
how variadic functions work (va_list, va_start, va_arg, va_end), 
how to read and handle a format string, 
how to manually print characters, strings, and integers, 
and how recursion can be used to print numbers.

%c :prints a single character

%s :prints a string of characters

%d :prints a signed integer

%i :prints a signed integer

%% :prints the % character

Prototype : int _printf(char *format, ...);

@_printf : Goes through the format string,
when it finds a %, it checks the next character to know what to print,
it gets the matching argument and calls the right function to print it (char, string, number),
in the end, it returns how many characters were printed

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

<img width="1215" height="1800" alt="Flowchart (1)" src="https://github.com/user-attachments/assets/9ae34fed-17f5-4f67-8a5f-7edc969a3df8" />

