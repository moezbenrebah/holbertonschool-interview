#include "lists.h"

/**
 *insert_node - insert node at a nth position
 *@head: double pointer to a head
 *@number: integer
 *
 *Return: address a node to insert
 */


listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp, *new_node;


	if (head == NULL)
		return (NULL);

	
	/* if the linked list is empty */

	if (!*head)
	{
		return (add_nodeint_end(head, number));
	}

	/* allocate memory to new_node */
	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;


	tmp = *head;

	/* check if the n stored in head is greater
	 * than the new node one 
	 */

	if (tmp->n > number)
	{
		*head = new_node;
		new_node->next = tmp;
		return (new_node);
	}

	/* find the new_node appropriate position */

	while (tmp->next && tmp->next->n < new_node->n)
	{
		tmp = tmp->next;
	}
	
	new_node->next = tmp->next;
	tmp->next = new_node;

	return (new_node);
}
