#include <stdarg.h>
#include "main.h"

#define NORMAL_STATE 0
#define SPECIFIER_STATE 1
#define false 0
#define true 1

/**
 * _printf - formats strings like printf
 * @format: the input string
 *
 * Return: 0 on sucess.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int state = NORMAL_STATE;
	int i;
	char *str;
	int n;

	
	va_start(ap, format);
	while (*format)
	{
		switch(state)
		{
			case NORMAL_STATE:
				switch(*format)
				{
					case '%':
						state = SPECIFIER_STATE;
						break;
					default:
						_putchar(*format);
						break;
				}
				break;
			case SPECIFIER_STATE:
				switch(*format)
				{
					case 'c':
						_putchar(va_arg(ap, int));
						break;
					case 's':
						_puts(va_arg(ap, char *));
						break;
					case '%':
						_putchar('%');
						break;
					case 'i':
					case 'd':
						i = va_arg(ap, int);
						if (i < 0)
						{
							i = -i;
							_putchar('-');
						}
						_puts(convert(i, 10));
						break;
					case 'b':
						i = va_arg(ap, unsigned int);
						_puts(convert(i, 2));
						break;
					case 'u':
						i = va_arg(ap, unsigned int);
						_puts(convert(i, 10));
						break;
					case 'x':
						i = va_arg(ap, unsigned int);
						_puts(convert(i, 16));
						break;
					case 'X':
						i = va_arg(ap, unsigned int);

						str = convert(i, 16);
						for (n = 0; str[n]; n++)
						{
							if (str[n] >= 97 && str[n] <= 102)
								str[n] = str[n] - 32;
						}
						_puts(str);
						break;
					case 'o':
						i = va_arg(ap, unsigned int);
						_puts(convert(i, 8));
					default:
						break;
				}
				state = NORMAL_STATE;
				break;
		}
		format++;
	}
return (0);
}
