#include "palindrome.h"

/**
 * is_palindrome - determines if a unsigned long is a palintrome
 * @n: unsigned integer
 * Return: 1 is palindrome or 0 if not
 */

int is_palindrome(unsigned long n)
{
	static unsigned long v, rev;


	if (n > 0)
	{
		v = n % 10;
		rev = (rev * 10) + v;
		is_palindrome(n / 10);
	}
	if (rev == n)
		return (1);
	else
		return (0);
}
