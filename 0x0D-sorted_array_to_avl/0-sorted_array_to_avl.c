#include "binary_trees.h"

/**
 * build_node - set the left AVL node of a parent node
 * @array: pointer to first array item
 * @parent: pointer to the parent node
 * @start: first index of the subarray.
 * @end: last index of the subarray.
 * Return: a pointer to the root node
 */

avl_t *build_node(int *array, avl_t *parent, int start, int end)
{
	avl_t *new_node;
	int size, mid, n;

	if (start > end)
		return (NULL);

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);

	size = start + end;
	mid = (size / 2);
	n = array[size / 2];

	new_node->parent = parent;
	new_node->n = n;
	new_node->left = build_node(array, new_node, start, mid - 1);
	new_node->right = build_node(array, new_node, mid + 1, end);

	return (new_node);
}


/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: a pointer to the first array item
 * @size: the size of the array
 * Return: A pointer to the root node, otherwise NULL
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	int n, mid;

	if (!array || size <= 0)
		return (NULL);

	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);

	mid = (size - 1) / 2;
	n = array[(size - 1) / 2];

	root->parent = NULL;
	root->n = n;
	root->left = build_node(array, root, 0, mid - 1);
	root->right = build_node(array, root, mid + 1, size - 1);

	return (root);
}
