#include "../../inc/push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*second_last;
	t_node	*last;

	last = *stack;
	second_last = NULL;
	if (!stack)
		return ;
	while (last ->next != NULL)
	{
		second_last = last;
		last = last -> next;
	}
	second_last -> next = NULL;
	last -> next = *stack;
	*stack = last;
}

void	 rev_rotate(t_node **stack, char c)
{
	if(c == 'a')
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
	else if(c == 'b')
	{
		reverse_rotate(stack);
		ft_printf("rrb\n");
	}
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *better)
{
		while (*b != better->tag_node && *a != better)
		{
			reverse_rotate(a);
			reverse_rotate(b);
			ft_printf("rrr\n");
		}
		node_ind(*a);
		node_ind(*b);
}