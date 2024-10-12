#include "../../inc/push_swap.h"

void	tag_node_b(t_node *stack_a, t_node *stack_b)
{
	t_node		*temp_a;
	t_node		*temp_tag;
	long		better_index;

	while (stack_b)
	{
		better_index = LONG_MAX;
		temp_a = stack_a;
		while (temp_a)
		{
			if (temp_a->nbr > stack_b->nbr && temp_a->nbr < better_index)
			{
				temp_tag = temp_a;
				better_index = temp_a->nbr;
			}
			temp_a = temp_a->next;
		}
		if (better_index == LONG_MAX)
			stack_b->tag_node = stack_min(stack_a);
		else
			stack_b->tag_node = temp_tag;
		stack_b = stack_b->next;
	}
}

void	init_push_b(t_node *stack_a, t_node *stack_b)
{
	node_ind(stack_a);
	node_ind(stack_b);
	tag_node_b(stack_a, stack_b);
}
