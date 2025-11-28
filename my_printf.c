#include "main.h"

/**
 * my_printf - simplified printf implementation
 * @format: format string containing directives
 *
 * Return: total number of printed characters, or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '%') /* print % */
            {
                putchar('%');
                count++;
            }
            else if (*format == 'c') /* print char */
            {
                int ch = va_arg(args, int);
                putchar(ch);
                count++;
            }
            else if (*format == 's') /* print string */
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    putchar(*str);
                    str++;
                    count++;
                }
            }
            else if (*format == 'd' || *format == 'i') /* print integer */
            {
                int nbr = va_arg(args, int);
                count += print_digit(nbr);
            }
            else /* unknown specifier, print as is */
            {
                putchar(*format);
                count++;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}


/**
 * print_char - write one character
 * @c: character to write
 *
 * Return: number of written bytes
 */
int print_char(int c)
{
    return write(1, &c, 1);
}


/**
 * print_str - write a string
 * @str: pointer to string
 *
 * Return: number of written characters
 */
int print_str(char *str)
{
    int count = 0;

    while (*str)
    {
        count += print_char(*str);
        str++;
    }
    return count;
}


/**
 * print_digit - print an integer recursively
 * @nbr: integer to print
 *
 * Return: number of printed characters
 */
int print_digit(int nbr)
{
    int count = 0;

    if (nbr < 0)
    {
        putchar('-');
        count++;
        nbr = -nbr;
    }

    if (nbr / 10)
        count += print_digit(nbr / 10);

    putchar((nbr % 10) + '0');
    count++;
    return count;
}