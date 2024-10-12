#include "../../inc/push_swap.h"

static void	rot(t_node **stack)
{
	t_node	*last;
	t_node	*first;

	last = *stack;
	first = *stack;
	if (!stack)
		return ;
	while (last -> next != NULL)
		last = last-> next;
	*stack = first -> next;
	first -> next = NULL;
	last -> next = first;
}

void	rotate(t_node **stack, char c)
{
	if (c == 'a')
	{
		rot(stack);
		ft_printf("ra\n");
	}
	else if (c == 'b')
	{
		rot(stack);
		ft_printf("rb\n");
	}
}

void	rotate_both(t_node **a, t_node **b, t_node *better)
{
	while (*b != better->tag_node && *a != better)
	{
		rot(a);
		rot(b);
		ft_printf("rr\n");
	}
	node_ind(*a);
	node_ind(*b);
}
