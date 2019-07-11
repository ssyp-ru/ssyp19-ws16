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
