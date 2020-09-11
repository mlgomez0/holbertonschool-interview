#include "palindrome.h"

/**
 * is_palindrome - prints all elements of a listint_t list
 * @n: pointer to head of list
 * Return: number of nodes
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
