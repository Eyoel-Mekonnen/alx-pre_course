#include "main.h"
int hexxa(int num)
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
 * print_nonchar - prints non printable char using hexa
 * @ptr: pointer of Va_list
 *
 * Return: Adress of string
 */
char *print_nonchar(va_list ptr)
{
	int i, j = 0, taker, len = 0;
	char *c;
	char *tmp;
	char *new;

	c = va_arg(ptr, char *);
	tmp = c;
	while(tmp[len] != '\0')
		len++;
	new = (char *)malloc(sizeof(char) * (len + 3));
	if (new == NULL)
		return (NULL);
	for (i = 0; c[i] != '\0'; i++)
	{
		if ((c[i] >= 0 && c[i] <= 32) || (c[i] >= 127))
		{
			new[j] = 92;
			++j;
			new[j] = 'x';
			++j;
			new[j] = '0';
			++j;
			taker = c[i];
			while (taker)
			{
				if (taker % 16 >= 10)
				{
					new[j] = hexxa(taker % 16);
					taker = taker / 16;
					++j;
				}
				else if (taker % 16 < 10)
				{
					new[j] = (taker % 16) + '0';
					taker = taker / 16;
					++j;
				}
			}
		}
		else
		{
			new[j] = c[i];
			++j;
		}
	}
	
	return (new);
}
