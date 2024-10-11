
#include "../../inc/push_swap.h"

static void	swap_stack(t_node *stack)
{
	int	temp;

	if (!stack)
		return ;
	temp = stack -> nbr;
	stack -> nbr = stack -> next -> nbr;
	stack -> next -> nbr = temp;
}

void	swap(t_node **stack, char c)
{
	if(c == 'a')
	{
		swap_stack(*stack);
		ft_printf("sa\n");
	}
	else if(c == 'b')
	{
		swap_stack(*stack);
		ft_printf("sb\n");
	}
}

void	swap_both(t_node **stack_a, t_node **stack_b)
{
	swap_stack(*stack_a);
	swap_stack(*stack_b);
	ft_printf("ss\n");
}