#include "main.h"

/**
  *_printf- printf function
  *@format: print format
  * Return: printed characters
  */
int _printf(const char *format, ...)
{
	va_list ptr;
	unsigned int length = 0, Q = 0;

	if (format == NULL)
		return (-1);
	va_start(ptr, format);

	while (format[Q] != '\0')
	{
		for (; format[Q] != '%' && format[Q]; Q++)
		{
			write(1, &format[Q], 1);
			length++;
		}
		if (!format[Q])
		{
			return (length);
		}
		if (get_handle_format(&format[Q + 1], &length, ptr))
		{
			Q += 2;
			continue;
		}
		if (format[Q + 1] == '%')
		{
			write(1, &format[Q], 1);
			length++;
			Q += 2;
			continue;
		}
		write(1, &format[Q], 1);
		length++;
		Q++;
	}
	va_end(ptr);
	return (length);
}
