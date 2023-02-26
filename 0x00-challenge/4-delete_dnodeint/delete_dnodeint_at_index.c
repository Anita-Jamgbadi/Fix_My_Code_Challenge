#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}

	current_node = *head;
	p = 0;

	while (p < index && current_node != NULL)
	{
		current_node = current_node->next;
		p++;
	}

	if (p != index)
	{
		return (-1);
	}

	if (current_node == *head)
	{
		*head = (*head)->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(current_node);
	}
	else if (current_node->next == NULL)
	{
		current_node->prev->next = NULL;
		free(current_node);
	}
	else
	{
		current_node->prev->next = current_node->next;
		current_node->next->prev = current_node->prev;
		free(current_node);
	}

	return (1);
}
