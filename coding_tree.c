#include "coding_tree.h"


void ctree_free_tree(ctree_node *a)
{
    if (a->children[0] != NULL)
    {
        ctree_free_tree(a->children[0]);
    }
    if (a->children[1] != NULL)
    {
        ctree_free_tree(a->children[1]);
    }
    free(a);
}

ctree_node *new_ctree_node(unsigned int freq, char letter, ctree_node *child_0, ctree_node *child_1)
{
    ctree_node *nov = (ctree_node *) malloc(sizeof(ctree_node));
    nov->freq = freq;
    nov->letter = letter;
    nov->children[0] = child_0;
    nov->children[1] = child_1;
    return nov;
}

void ctree_sort(ctree_node *mass_of_nodes[], int index)
{
	ctree_node* swap;
	for (int i = index; i > 0; i--)
		{
		if (mass_of_nodes[i] > mass_of_nodes[i-1])
		{
			swap = mass_of_nodes[i-1];
			mass_of_nodes[i-1] = mass_of_nodes[i];
			mass_of_nodes[i] = swap;
		}
		else
		{
			break;
		}
	}
}

ctree_node *ctree_build_tree(unsigned int mass_of_int[])
{
	int count = 0;
	ctree_node *mass_of_nodes[BUFFER_SIZE];
    for (int j = 0; j < BUFFER_SIZE; j++)
    {
        if (mass_of_int[j] != 0)
        {
			mass_of_nodes[count] = new_ctree_node(mass_of_int[j], j, NULL, NULL);
			count++;
        }
    }
    for (int i = 1; i < count; i++)
	{
		ctree_sort(mass_of_nodes, i);
	}
    for (int index = count; index > 0; index--)
    {
        mass_of_nodes[index - 1] = new_ctree_node(mass_of_nodes[index]->freq + mass_of_nodes[index - 1]->freq,
                                                  0, mass_of_nodes[index], mass_of_nodes[index - 1]);
        ctree_sort(mass_of_nodes, index - 1);
    }
    return mass_of_nodes[0];
}
