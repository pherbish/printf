#include "main.h"

/**
  *_printf- printf function
  *@format: print format
  * Return: printed characters
  */
int _printf(const char *format, ...)
{
	int lchar = 0;
	va_list strargs;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(strargs, format);

	while (*format)
	{
		if (*format != '%')
		{
		write(1, format, 1);
		lchar++;
		}
		else
		{
		format++;

		if (*format == '\0')
			break;

		if (*format == '%')
		{
			write(1, format, 1);
			lchar++;
		}
		else if (*format == 'd')
		{
			int d = va_arg(strargs, int);
			int i = 0;

			while (d[i] !='\0')
			{
				i++;
				write(1, d, i);
				lchar += i;
			}
		else if (*format == 'c')
		{
			char c = va_arg(strargs, int);
				write(1, &c, 1);
			lchar++;
		}
		else if (*format == 's')
		{
			char *s = va_arg(strargs, char *);
			int str_len = 0;

			while (s[str_len] != '\0')
			{
				str_len++;
				write(1, s, str_len);
				lchar += str_len;
			}
		}
	}
	format++;
	}
va_end(strargs);
return (lchar);
}
