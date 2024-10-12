#include "../../inc/push_swap.h"

void	cost_a(t_node *stack_a, t_node *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_med))
			stack_a->push_cost = size_a - (stack_a->index);
		if (stack_a->tag_node->above_med)
			stack_a->push_cost += stack_a->tag_node->index;
		else
			stack_a->push_cost += size_b - (stack_a->tag_node->index);
		stack_a = stack_a->next;
	}
}

void	tag_node_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*temp_b;
	t_node	*temp_tag;
	long 		better_index;

	while(stack_a)
	{
		better_index = LONG_MIN;
		temp_b = stack_b;
		while(temp_b)
		{
			if(temp_b->nbr < stack_a->nbr && temp_b->nbr > better_index)
			{
				better_index = temp_b->nbr;
				temp_tag = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (better_index == LONG_MIN)
			stack_a->tag_node = stack_max(stack_b);
		else
			stack_a->tag_node = temp_tag;
		stack_a = stack_a->next;
	}
}

void	init_push_a(t_node *stack_a, t_node *stack_b)
{
	node_ind(stack_a);
	node_ind(stack_b);
	tag_node_a(stack_a, stack_b);
	cost_a(stack_a, stack_b);
	better_move(stack_a);
}