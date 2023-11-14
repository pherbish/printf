#include "main.h"

/**
 *_printf- printf function
 *@format: print format
 *Return: printed characters
 */
int _printf(const char *format, ...)
{
	int i = 0, printed = 0, lchar = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(strargs, format);
	while (*format)
	{
		if (*format != '%')
		{write(1, format, 1);
		lchar++; }
		else
		{format++;
		if (*format == '\0')
			break;
		if (*format == '%')
			{write(1, format, 1);
			lchar++; }
		else if (*format == 'c')
		{char c = va_arg(strargs, int);
				write(1, &c, 1);
			lchar++; }
		else if (*format == 's')
		{char *s = va_arg(strargs, char *);
			int str_len = 0;

			while (s[str_len] != '\0')
			{str_len++;
				write(1, s, str_len);
				lchar += str_len; }
		}
		}
	format++;
	}
va_end(strargs);
return (lchar);
}

