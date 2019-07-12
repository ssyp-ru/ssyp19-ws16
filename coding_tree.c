#include "coding_tree.h"

void ctree_free_tree (ctree_node *a)
{
	if (a -> children[0] != NULL)
	{
		ctree_free_tree(a->children[0]);
	}
	if (a -> children[1] != NULL)
	{
		ctree_free_tree(a->children[1]);
	}
	free (a);
}

ctree_node *new_ctree_node (unsigned int freq, char letter, *child[0], *child[1])
{
	ctree_node *nov = (ctree_node *) malloc(sizeof(ctree_node));
	nov-> freq = freq;
	nov -> letter = letter;
	nov->children[0] = child[0];
	nov->children[1] = child[1];
	return nov;
}

ctree_node* ctree_sort (ctree_node* mass_of_nodes)
{
	ctree_node* cur_node, swap;
	for(int index = 0; index < 257; index++)
	{
		cur_node = mass_of_nodes[index];
		while (cur_node != mass_of_nodes[0])
		{
			if (cur_node->freq > mass_of_nodes[index - 1]->freq)
			{
				swap = mass_of_nodes[index - 1];
				mass_of_nodes[index - 1] = thing;
				mass_of_nodes[index] = swap;
			}
			else
			{
				continue;
			}
		}
	}
}
ctree_node* ctree_build_tree (unsigned int* mass_of_int)
{
	for(int j = 0; j < 257; j++)
	{
		if (mass_of_int[j] == NULL)
		{
			free(mass_of_int[j]);
		}
	}
	ctree_node* mass_of_nodes[257];
	for(int i = 0; i < 257; i++)
	{
		mass_of_nodes[i] = new_ctree_node(mass_of_int[i], i, NULL, NULL);
	}
	ctree_node* ctree_sort(mass_of_nodes);
	for(int index = 256; index > 0; index--)
	{
		mass_of_nodes[index - 1] = new_ctree_node(mass_of_nodes[index] + mass_of_nodes[index-1], '0', mass_of_nodes[index], mass_of_nodes[index-1]);
	}
	return mass_of_nodes[0];
}
