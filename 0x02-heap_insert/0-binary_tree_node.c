#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: a pointer to the root node
 * @value: the value of the node
 *
 * Return: a pointer to new node
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = malloc(sizeof(binary_tree_t));
	if (!newnode)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;

	return (newnode);
}
