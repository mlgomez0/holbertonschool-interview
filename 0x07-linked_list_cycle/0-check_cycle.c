#include "lists.h"

/**
 * check_cycle - checks is a single linked list has a loop
 * @list: pointer to head of list
 * Return: 0 if not loop and 1 if loop
 */


int check_cycle(listint_t *list)
{
	listint_t *temp1 = list;
	listint_t *temp2 = list;

	while (temp1 && temp2)
	{
		temp1 = temp1->next;
		temp2 = temp2->next->next;
		if (temp1 == temp2)
			return (1);

	}
	return (0);
}
