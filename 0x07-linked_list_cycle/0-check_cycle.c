#include "lists.h"


/**
 * check_cycle - a function to check if a given linked list has a cycle
 * @list: a linked list
 *
 * Return: 1 if has a cycle, otherwise 0
 */

int check_cycle(listint_t *list)
{
	listint_t *one_feet = list;
	listint_t *two_feets = list;

	while (one_feet && two_feets && two_feets->next)
	{
		one_feet = one_feet->next;
		two_feets = two_feets->next->next;

		if (one_feet == two_feets)
			return (1);
	}

	return (0);
}
