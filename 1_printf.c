#include "main.h"
#include <stdlib.h>
/**
 *print_char-prints character
 *@c:character to be printed
 *Return:character
 */
int print_char(int c)
{
	return (write(1, &c, 1));
}
/**
 * print_str-prints string
 * @str:string printed
 * Return:string
 */
int print_str(char *str)
{
	int counter = 0;

	while (*str != '\0')
	{
		print_char((int)(*str));
		++counter;
		++str;
	}
	return (counter);
}
/**
 * print_digit-prints given digit
 * @n:number of values
 * @base:base 10 or 16
 * Return: integers
 */
int print_digit(long n,int b)
{
	int count;
	char *symbols;

	symbols = "0123456789abcdef";

	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, b) + 1);
	}
	else if (n < b)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / b, b);
		return (count = print_digit(n % b, b));
	}
}
/**
 * format_specifier -selects format
 * @specifier:types
 * @ap:array of arguments
 * Return:format
 */
int format_specifier(char specifier, va_list ap)
{
	int count = 0;

	if (specifier == 'c')
	{
		count += print_char(va_arg(ap, int));
	}
	else if (specifier == 's')
	{
		count += print_str(va_arg(ap, char *));
	}
	else if (specifier == 'd')
	{
		count += print_digit((long)(va_arg(ap, int)), 10);
	}
	else if (specifier == 'x')
	{
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
	}
	else
		write(1, &specifier, 1);
	return (count);

}
/**
 * _printf-prints array of arguments
 * @format:constant argument
 * Return: printed arguments
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += _printf(*(++format), ap);
		}
		else
		{
			count += write(1, format, 1);
		}
		++format;
	}
	va_end(ap);
	return (count);
