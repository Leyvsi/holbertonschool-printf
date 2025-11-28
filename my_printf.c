#include "main.h"


/**
 * _printf - simplified printf
 * @format: format string
 *
 * Return: number of printed characters, or -1 on error
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
            format++; /* move to specifier */

            if (*format == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else if (*format == 'c')
            {
                int ch = va_arg(args, int);
                write(1, &ch, 1);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);

                if (str == NULL)
                    str = "(null)";

                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                int nbr = va_arg(args, int);
                count += print_digit(nbr);
            }
            else
            {
                /* unknown specifier: print literally */
                write(1, format, 1);
                count++;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }

        format++; /* one increment per loop */
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
 * print_digit - print integer recursively
 * @nbr: number to print
 *
 * Return: number of printed chars
 */
int print_digit(int nbr)
{
    int count;
    unsigned int num;
    char c;

    count = 0;

    if (nbr < 0)
    {
        count += write(1, "-", 1);
        num = -((unsigned int)nbr);
    }
    else
        num = nbr;

    if (num / 10)
        count += print_digit(num / 10);

    c = (num % 10) + '0';
    count += write(1, &c, 1);

    return count;
}