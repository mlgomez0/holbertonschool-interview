#include "lists.h"

/**
 * pali_recursive-makes recursion to a single linked list
 * @head: double pointer to linked list
 * @temp: pointer to linked list
 * @l: holds the lenght od the list
 * @n: counts until nodes are different
 */

void pali_recursive(listint_t **head, listint_t *temp, int *l, int *n)
{
	if (temp)
	{
		*l = *l + 1;
		pali_recursive(head, temp->next, l, n);
		if ((*head)->n == temp->n)
		{
			*head = (*head)->next;
			*n = *n + 1;
			return;
		}
		return;
	}
}

/**
 * is_palindrome-determines if linked list is palindrome
 * @head: double pointer to the linked list
 * Return: 1 if palindrome otherwhise 0
 */

int is_palindrome(listint_t **head)
{
	listint_t *temp = *head;
	listint_t *temp2 = *head;
	int lenght = 0, num = 0;

	if (!*head)
		return (1);
	pali_recursive(&temp, temp2, &lenght, &num);
	if (lenght == num)
		return (1);
	else
		return (0);
}
