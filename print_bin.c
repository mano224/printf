#include "main.h"

/**
 * print_bin - covert given number to
 * binary and print it using _putchar function
 * @list: list given
 * Return: number of prints
<<<<<<< HEAD
*/
=======
 */
>>>>>>> 64c4238a6c34136c72fc12a38bca7234a7f5ce76
int print_bin(va_list list)
{
	int *arr;
	int pr_count, i;
	unsigned int n, a;

	n = va_arg(list, int);
	a = n;
	pr_count = 0;

	while (a / 2)
	{
		pr_count++;
		a /= 2;
	}
	pr_count++;

	arr = (int *)malloc(sizeof(int) * pr_count);

	if (arr == NULL)
	{
		free(arr);
		return (0);
	}

	for (i = 0; i < pr_count; i++)
	{
		arr[i] = n % 2;
		n /= 2;
	}

	for (i = pr_count - 1; i >= 0; i--)
	{
<<<<<<< HEAD
	_putchar(arr[i] + '0');
=======
		_putchar(arr[i] + '0');
>>>>>>> 64c4238a6c34136c72fc12a38bca7234a7f5ce76
	}

	free(arr);
	return (pr_count);
}
