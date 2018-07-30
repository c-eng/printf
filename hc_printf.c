#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void _printf(const char *format, ...)
{
	int count, strcount = 0;
	char *start;
	unsigned int i;
	char *s;

	va_list arg;
	va_start(arg, format);

	for(; *format != '\0'; format++)
	{
		while(*format != '%')
		{
			putchar(*format);
			format++;
		}

		format++;
		switch(*format)
		{
		case 'c':
			i = va_arg(arg, int);
			putchar(i);
			break;
		case 's':
			s = va_arg(arg, char *);
			puts(s);
			break;
		}
	}
}
