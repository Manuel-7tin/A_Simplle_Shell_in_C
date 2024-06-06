#include <stdio.h>

/**
 * str_to_int - Converts a string to an integer
 *
 * @str: THe string to be converted
 *
 * Return: (int) THe generated number or a negative number on error
 */

int str_to_int(char *str)
{
	int result = 0, sign = 1, i = 0;

	if (str == NULL)
		return (-9);
	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-9);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
