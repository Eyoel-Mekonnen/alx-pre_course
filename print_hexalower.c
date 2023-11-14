#include "main.h"
/**
 * hexa - convert to hex alpha
 * @num: the number passed
 *
 * Return: character
 */
char hexa(int num)
{
	char c;

	switch (num)
	{
		case 10:
			c = 'a';
			break;
		case 11:
			c = 'b';
			break;
		case 12:
			c = 'c';
			break;
		case 13:
			c = 'd';
			break;
		case 14:
			c = 'e';
			break;
		case 15:
			c = 'f';
			break;
		default:
			break;
	}
	return (c);
}
/**
 * print_hexalower - prints hexa in lowercase
 * @ptr: pointer from va_list
 *
 * Return: char pointer
 */
char *print_hexalower(va_list ptr)
{
	unsigned int tmp, num;
	int i, count = 0;
	char *hexalower;

	num = va_arg(ptr, unsigned int);
	tmp = num;
	while (tmp)
	{
		tmp = tmp / 16;
		count++;
	}
	hexalower = (char *)malloc(sizeof(char) * (count + 1));
	if (hexalower == NULL)
		return (NULL);
	for (i = (count - 1); i >= 0; i--)
	{
		if (num % 16 >= 10)
		{
			hexalower[i] = hexa(num % 16);
			num = num / 16;
		}
		else if (num % 16 < 10)
		{
			hexalower[i] = (num % 16) + '0';
num = num / 16;
		}
	}
	hexalower[count] = '\0';
	return (hexalower);
}
