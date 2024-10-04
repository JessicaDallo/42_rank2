
void add_to_end_list(t_node *list, t_node *node)
{
	t_node *temp;

	if(list -> head == NULL)
	{
		list -> head = node;
		node -> next = NULL;
		return ;
	}
	else 
	{
		temp = list -> head;
		while (temp -> next != NULL)
			temp = temp -> next;
	}
	temp -> next = node;
	node -> next = NULL;
}


t_node *create_node(int nbr)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if(!node)
		return (NULL);
	node -> nbr = nbr;
	node -> next = NULL;
	return (node);
}

void init_list_a(t_node *list, char *str)
{
	char **initial;
	t_node *node;
	long n;

	initial = ft_split(str, ' ');
	if(initial != NULL)
	{
		while(*initial)
		{
			if(error_syntax(*initial))
				free_error(&list->head);
			n = atol(*initial);
			if(n > INT_MAX || n < INT_MIN)
				free_error(&list->head);
			node = create_node(n);
			add_to_end_list(list, node);
			if(error_duplicate(list, n) != 0)
				free_error(&list->head);
			initial++;
		}
	}
	
}