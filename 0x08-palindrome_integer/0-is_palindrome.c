#include "palindrome.h"


/**
 * is_palindrome - a function if a given integer is palidrome
 * @n: integer
 *
 * Return: 1 if integer is a palindrome, otherwise 0
 */

int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, num = n;

	while (num)
	{
		rev = rev * 10 + (num % 10);
		num = num / 10;
	}
	if (n == rev)
		return (1);
	return (0);
}
