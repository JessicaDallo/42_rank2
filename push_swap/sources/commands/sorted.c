#include "../../inc/push_swap.h"

//se 1 está ordenado, se 0 não;
int	is_sorted(t_node *stack_a)
{
	t_node	*current;

	current = stack_a;
	while (current->next != NULL)
	{
		if (current->nbr > current->next-> nbr)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a)
		return ;
	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	c = (*stack_a)->next->next->nbr;
	if (a < b && a < c && b > c)
	{
		rev_rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
	else if (a > b && a < c && b < c)
		swap(stack_a, 'a');
	else if (a < b && a > c && b > c)
		rev_rotate(stack_a, 'a');
	else if (a > b && a > c && b < c)
		rotate(stack_a, 'a');
	else if (a > b && a > c && b > c)
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	min;

	min = stack_min(*stack_a)->nbr;
	max = stack_max(*stack_a)->nbr;
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->nbr == min || (*stack_a)->nbr == max)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, 'a');
	if ((*stack_a)->nbr == min && !is_sorted(*stack_a))
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (!is_sorted(*stack_a))
		rotate(stack_a, 'a');
}
