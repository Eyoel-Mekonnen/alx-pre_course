#include "main.h"
/**
 * hexacap - converts digit to capital alpha
 * @num: the number passed
 *
 * Return: char c
 */
char hexacap(int num)
{
	char c;

	switch (num)
	{
		case 10:
			c = 'A';
			break;
		case 11:
			c = 'B';
			break;
		case 12:
			c = 'C';
			break;
		case 13:
			c = 'D';
			break;
		case 14:
			c = 'E';
			break;
		case 15:
			c = 'F';
			break;
		default:
			break;
	}
	return (c);
}
/**
 * print_hexacapital - prints hexadecimal with capital
 * @ptr - pointer of type va_list
 *
 * Return: Adress of string
 */
char *print_hexacapital(va_list ptr)
{
	unsigned int tmp, num;
	int i, count = 0;
	char *hexacapital;

	num = va_arg(ptr, unsigned int);
	tmp = num;
	while (tmp)
	{
		tmp = tmp / 16;
		count++;
	}
	hexacapital = (char *)malloc(sizeof(char) * (count + 1));
	if (hexacapital == NULL)
		return (NULL);
	for (i = (count - 1); i >= 0; i--)
	{
		if (num % 16 >= 10)
		{
			hexacapital[i] = hexacap(num % 16);
			num = num / 16;
		}
		else if (num % 16 < 10)
		{
			hexacapital[i] = (num % 16) + '0';
			num = num / 16;
		}
	}
	hexacapital[count] = '\0';
	return (hexacapital);
}
