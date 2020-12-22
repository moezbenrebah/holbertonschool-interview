#include "binary_trees.h"

/**
 *binary_tree_node - function to create a binray tree
 *@parent: a binary tree root node
 *@value: integer
 *
 *Return: pointer to new node, otherwise NULL
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
        binary_tree_t *new;

        new = malloc(sizeof(binary_tree_t));
        if (!new)
                return (NULL);

        new->n = value;
        new->left = NULL;
        new->right = NULL;
        new->parent = parent;

        return (new);
}

