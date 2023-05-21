#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: a pointer to the memory previously allocated with a call to malloc.
 * @old_size: the size, in bytes, of the allocated space for ptr.
 * @new_size: the new size, in bytes of the new memory block.
 *
 * Return: a pointer, or NULL if it fails.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	/* If new size is 0 and ptr is not NULL, free memory and return NULL */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	/* If ptr is NULL, allocate memory of new size and return pointer */
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	/* If new size is equal to old size, return ptr */
	if (new_size == old_size)
		return (ptr);
	/*
	 * If ptr is not NULL and new_size is not equal to 0 or old_size,
	 * allocate new memory of new size.
	 */
	ptr = malloc(new_size);

	return (ptr);
}

/**
 * _atoi - converts a string to an integer.
 * @s: string to convert.
 *
 * Return: the converted integer.
 */
int _atoi(char *s)
{
	int i = 0, result = 0, sign = 1;

	/* Skip any leading non-digit characters */
	while ((s[i] < '0' || s[i] > '9') && s[i] != 0)
	{
		/*If the first character is '-' set the sign multiplier to -1*/
		if (s[0] == '-')
			sign *= -1;
		i++;
	}
	/* Convert the string to an integer */
	while ((s[i] >= '0' && s[i] <= '9') && s[i] != 0)
	{
		result = result * 10 - (s[i] - '0');
		i++;
	}
	/* Apply the sign multiplier to the final result */
	sign *= -1;

	/* Multiply the result by the sign multiplier */
	return (result * sign);
}

/**
 * _ctrl_c_signal_handler - handles the signal triggered by the use of CTRL-C.
 * @signal: the signal number.
 *
 * Return: void
 */
void _ctrl_c_signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		/* Return to the console */
		_print("\n$ ");
		/* Clear the output buffer and move the buffered data to the console */
		fflush(stdout);
	}
}
/**
 * int_to_str - converts an integer to a string.
 * @num: the integer to be converted.
 *
 * Return: string format after conversion.
 */
char *int_to_str(int num)
{
	int is_negative = 0, tmp = num, digits = 0, i;
	char *str;

	/* Check if the number is negative */
	if (num < 0)
	{
		is_negative = 1;
		num *= -1;
	}
	/* Count the number of digits in the number */
	while (tmp > 0)
	{
		digits++;
		tmp /= 10;
	}
	/* Special case for zero, it has 1 digit */
	if (num == 0)
		digits = 1;
	/* Increase the digit count if the number is negative */
	if (is_negative)
		digits++;
	/* Allocate memory for the string representation of the number */
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	/* Set the null-terminator at the end of the string */
	str[digits] = '\0';
	/*If num is negative set minus sign at the beginning of the string*/
	if (is_negative)
		str[0] = '-';
	/*Convert each digit of num to a character and store it in the string*/
	for (i = digits - 1; i >= is_negative; i--)
	{
		str[i] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
