#include "main.h"

/**
 * print_octal - prints octal
 * @ptr: recieves pointer of type va_list
 *
 * Return: Adress of char
 */
char *print_octal(va_list ptr)
{
	unsigned int num, tmpo;
	int count = 0, i;
	char *octal;

	num = va_arg(ptr, unsigned int);
	tmpo = num;
	while (tmpo)
	{
		tmpo = tmpo / 8;
		count++;
	}
	octal = (char *)malloc(sizeof(char) * (count + 1));
	for (i = (count - 1); i >= 0; i--)
	{
		octal[i] = (num % 8) + '0';
		num = num / 8;
	}
	octal[count] = '\0';
	return (octal);
}
