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
typedef st_ctree_node node;
struct st_ctree_node
{
    char letter;
    unsigned int freq;
    node children[2];
};
node *new_node (int freq, char letter)
{
	node *nov = (node *) malloc(sizeof(node));
	nov-> freq = freq;
	nov -> letter = "letter"
	nov->children[0] = NULL;
	nov->children[1] = NULL;
	return nov;
}
