#include "main.h"

/**
  *_printf- printf function
  *@format: print format
  * Return: printed characters
  */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
	va_list ptr;
	unsigned int length = 0, Q = 0;
=======
	int lchar = 0;
	va_list strargs;
>>>>>>> 1f017cf772d288c24d2eba2ba598cb28f4d24d40

	if (format == NULL)
		return (-1);
<<<<<<< HEAD
	va_start(ptr, format);

	while (format[Q] != '\0')
=======
	}
	va_start(strargs, format);

	while (*format)
>>>>>>> 1f017cf772d288c24d2eba2ba598cb28f4d24d40
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
<<<<<<< HEAD
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
=======
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
>>>>>>> 1f017cf772d288c24d2eba2ba598cb28f4d24d40
}
