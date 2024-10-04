#include "../../inc/push_swap.h"

//se 1 está ordenado, se 0 não;
int	is_sorted(t_node *list)
{
	t_node	*current;

	current = list;
	while (current->next != NULL)
	{
		if (current->nbr > current->next-> nbr)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_node **list)
{
	int	a;
	int	b;
	int	c;

	if (!list)
		return ;
	a = (*list)->nbr;
	b = (*list)->next->nbr;
	c = (*list)->next->next->nbr;
	if (a < b && a < c && b > c)
	{
		reverse_rotate(list, 'a');
		swap_stack(*list, 'a');
	}
	else if (a > b && a < c && b < c)
		swap_stack(*list, 'a');
	else if (a < b && a > c && b > c)
		reverse_rotate(list, 'a');
	else if (a > b && a > c && b < c)
		rotate(list, 'a');
	else if (a > b && a > c && b > c)
	{
		rotate(list, 'a');
		swap_stack(*list, 'a');
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	max;

	min = list_min(stack_a);
	max = list_max(stack_a);
	while (list_size(stack_a) > 3)
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
		swap_stack(*stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (!is_sorted(*stack_a))
		rotate(stack_a, 'a');
}
