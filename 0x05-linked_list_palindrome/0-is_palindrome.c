#include "lists.h"


/**
 * check_palindrome - a function to check first and last values
 * of a given linked list equal or not
 * @first: double pointer to first node
 * @last: double pointer to last node
 *
 * Return: return true if left node equal right node, otherwise false
 */

bool check_palindrome(listint_t **first, listint_t *last)
{
	if (!last)
		return (1);

	bool result = check_palindrome(first, last->next);

	if (!result)
		return (0);

	bool result1 = (last->n == (*first)->n);
	*first = (*first)->next;

	return (result1);
}


/**
 * is_palindrome - a function to hecks if a singly linked list is a palindrome.
 * @head: double pointer to head node
 *
 * Return: 1 if it is a palindrome, otherwise 0
 */

int is_palindrome(listint_t **head)
{

	if (!(*head) || !head)
		return (1);

	if (check_palindrome(&(*head), *head))
		return (1);
	else
		return (0);
}
