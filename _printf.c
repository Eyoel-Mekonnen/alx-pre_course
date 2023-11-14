#include "main.h"
#include <string.h>
/**
 * _printf - produces output according to format
 * @format: the format string passed
 *
 * Return: an integer Value
 */
int _printf(const char *format, ...)
{
	type_format spec[] = {
		{"%c", print_char}, {"%s", print_string}, {"%d", print_integer}, {"%u", print_unsigned_integer}, {"%b", print_binary}, {"%r", reverse_string}
	};
	 int i, j, k, length, buffpos = 0;
	char buffer[1024];
	char *tmp;
	va_list ptr;

	va_start(ptr, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			/**
			if (format[i] == '%')
			{
				buffer[buffpos] = '%';
				buffpos++;
			}
			**/
			j = 0;
			while (spec[j].f_s)
			{
				if (format[i] == spec[j].f_s[1])
				{
					tmp = spec[j].func(ptr);
					length = strlen(tmp);
					for (k = 0; k < length; k++)
					{
						buffer[buffpos] = tmp[k];
						buffpos++;
					}
					break;
				}
				else
					j++;
			}
		}
		else if (format[i] != '%' && format[i] != '\0')
		{
			buffer[buffpos] = format[i];
			buffpos++;
		}
	}
	buffer[buffpos] = '\0';
	write (1,buffer, buffpos);
	va_end(ptr);
	return (buffpos);
}
