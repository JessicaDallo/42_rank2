#include "../../inc/push_swap.h"

void	min_top(t_node **stack_a)
{
	while((*stack_a)->nbr != stack_min(*stack_a)->nbr)
	{
		if (stack_min(*stack_a)->above_med)
			rotate(stack_a, 'a');
		else
			rev_rotate(stack_a, 'a');
	}

}

void	b_to_a(t_node **stack_a, t_node **stack_b)
{
	pre_push(stack_a, (*stack_b)->tag_node, 'a');
	push(stack_b, stack_a, 'a');
}


void	a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*better_node;

	better_node = get_better(*stack_a);
	if (better_node->above_med && (better_node->tag_node->above_med))
	{
		rotate_both(stack_a, stack_b, better_node);
	}
	else if (!(better_node->above_med) && !(better_node->tag_node->above_med))
		rev_rotate_both(stack_a, stack_b, better_node);
	pre_push(stack_a, better_node, 'a');//para ter certeza que o nó mais barato está em cima
	pre_push(stack_b, better_node->tag_node, 'b'); //para ter certeza que o tag node est+á em cima e pronto para push
	push(stack_a, stack_b, 'b');
}


void	ordering(t_node **stack_a, t_node **stack_b)
{
	int	size_a;

	size_a = stack_size(*stack_a);
	if(size_a-- > 3 && !is_sorted(*stack_a))
		push(stack_a, stack_b, 'b');
	if(size_a-- > 3 && !is_sorted(*stack_a))
		push(stack_a, stack_b, 'b');
	while(size_a-- > 3 && !is_sorted(*stack_a))
	{
		init_push_a(*stack_a, *stack_b);
		a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while(*stack_b)
	{
		init_push_b(*stack_a, *stack_b);
		b_to_a(stack_a, stack_b);
	}
	node_ind(*stack_a);
	min_top(stack_a);
}