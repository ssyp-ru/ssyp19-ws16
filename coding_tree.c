#include "coding_tree.h"

void ctree_free_tree (ctree_node *a)
{
	if (a -> children[0] != NULL)
	{
		del_tree (a->children[0]);
	}
	if (a -> children[1] != NULL)
	{
		del_tree (a->children[1]);
	}
	free (a);
}
typedef st_ctree_node ctree_node;
struct st_ctree_node
{
    char letter;
    unsigned int freq;
    ctree_node children[2];
};
ctree_node *new_ctree_node (unsigned int freq, char letter, *child[0], *child[1])
{
	ctree_node *nov = (ctree_node *) malloc(sizeof(ctree_node));
	nov-> freq = freq;
	nov -> letter = letter;
	nov->children[0] = child[0];
	nov->children[1] = child[1];
	return nov;
}
