#include "binary_trees.h"


/**
 * binary_tree_depth - return the depth of a given binary tree
 * @tree: a pointer to a root node
 *
 * Return: return the height of a given binary tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	if (tree && tree->parent)
	{
		return (1 + binary_tree_depth(tree->parent));
	}
	return (0);
}


/**
 * binary_tree_is_leaf - check whether if node is leaf or not
 * @node: pointer to a node to check
 *
 * Return: 1 if a given node is leaf, otherwise return 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->left && !node->right)
		return (1);
	else
		return (0);
}


/**
 * insert_node - functin to insert a node in the right position
 * @node: pointer to node
 * @lvl: the insertion node level
 * @m: integer
 *
 * Return: a pointer to the node to insert
 */

binary_tree_t *insert_node(binary_tree_t *node, size_t lvl, int m)
{
	binary_tree_t *l, *r;

	if (!node)
		return (NULL);

	if (binary_tree_depth(node) == lvl)
	{
		if (binary_tree_is_leaf(node))
		{
			return (node->left = binary_tree_node(node, m));
		}

		if (node->left && !node->right)
		{
			return (node->right = binary_tree_node(node, m));
		}

		return (NULL);

	}

	l = insert_node(node->left, lvl, m);

	if (!l)
		r = insert_node(node->right, lvl, m);
	else
		return (l);
	return (r);
}


/**
 * binary_tree_height - return the height of a given binary tree
 * @tree: a pointer to a root node
 *
 * Return: return the height of a given binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t max_left, max_right, max = 0;

	if (tree)
	{
		max_left = tree->left ? binary_tree_height(tree->left) + 1 : 0;
		max_right = tree->right ? binary_tree_height(tree->right) + 1 : 0;


		max += (max_left > max_right ? max_left : max_right);
	}
	return (max);
}


/**
 * heap_insert - a function to insert a value into a Max binary heap
 * @root: a double pointer to the heap root node
 * @value: value to be inserted
 *
 * Return: the pointer to the inserted new node, otherwise NULL
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	size_t lvl, i, tmp;

	lvl = 0;

	if (!root)
		return (NULL);

	if (!(*root))
	{
		new_node = binary_tree_node(*root, value);
		*root = new_node;
		return (new_node);
	}

	lvl = binary_tree_height(*root);

	for (i = 0; i <= lvl; i++)
	{
		new_node = (heap_t *) insert_node((binary_tree_t *) *root,
								    i,
								    value);
		if (new_node)
			break;
	}

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		tmp = new_node->parent->n;
		new_node->parent->n = new_node->n;
		new_node->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}
