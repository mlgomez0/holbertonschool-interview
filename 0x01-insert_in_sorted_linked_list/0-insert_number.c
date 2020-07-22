#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - adds a new node in a sorted listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new node or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;
	listint_t *temp;

	if (head == NULL)
		return (NULL);
	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	if (number <= (*head)->n)
	{
		temp = *head;
		*head = new;
		new->next = temp;
		return (new);
	}
	while (current->next != NULL)
	{
		if (current->next->n >= number)
		{
			temp = current->next;
			current->next = new;
			new->next = temp;
			return (new);
		}
		current = current->next;
	}
	current->next = new;
	return (new);
}
