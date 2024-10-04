#include "../../inc/push_swap.h"

int	list_size(t_node **stack)
{
	int		i;
	t_node	*temp;

	temp = *stack;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	list_min(t_node **stack_a)
{
	int		i;
	t_node	*temp;

	temp = *stack_a;
	i = temp->nbr;
	while (temp != NULL)
	{
		if (i > temp->nbr)
			i = temp->nbr;
		temp = temp->next;
	}
	return (i);
}

int	list_max(t_node **stack_a)
{
	int		i;
	t_node	*temp;

	temp = *stack_a;
	i = temp->nbr;
	while (temp != NULL)
	{
		if (i < temp->nbr)
			i = temp->nbr;
		temp = temp->next;
	}
	return (i);
}
