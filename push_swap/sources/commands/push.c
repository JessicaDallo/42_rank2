#include "../../inc/push_swap.h"

void	push(t_node **stack_1, t_node **stack_2, char c)
{
	t_node	*temp;

	if (*stack_1)
	{
		temp = *stack_1;
		*stack_1 = (*stack_1)->next;
		temp->next = *stack_2;
		*stack_2 = temp;
	}
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}
