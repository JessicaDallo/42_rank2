#include "../../inc/push_swap.h"

void	better_move(t_node *stack)
{
	t_node		*better_node;
	long		cheap_nbr;

	if (!stack)
		return ;
	cheap_nbr = LONG_MAX;
	better_node = NULL;
	while (stack)
	{
		if (stack->push_cost < cheap_nbr)
		{
			cheap_nbr = stack->push_cost;
			better_node = stack;
		}
		stack = stack -> next;
	}
	better_node->cheap = 1;
}

void	node_ind(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_med = 1;
		else
			stack->above_med = 0;
		stack = stack->next;
		i++;
	}
}

t_node	*get_better(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

//top node porque precisa que o melhor node seja o top
void	pre_push(t_node **stack, t_node *top_node, char letter)
{
	while (*stack != top_node)
	{
		if (letter == 'a')
		{
			if (top_node->above_med)
				rotate(stack, 'a');
			else
				rev_rotate(stack, 'a');
		}
		else if (letter == 'b')
		{
			if (top_node->above_med)
				rotate (stack, 'b');
			else
				rev_rotate(stack, 'b');
		}
	}
}
