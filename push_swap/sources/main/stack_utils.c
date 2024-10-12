#include "../../inc/push_swap.h"

int	stack_size(t_node *stack)
{
	int		i;
	t_node	*temp;

	temp = stack;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_node	*stack_min(t_node *stack_a)
{
	t_node		*temp_min;
	t_node		*temp;
	long		i;

	temp = stack_a;
	i = LONG_MAX;
	while (temp != NULL)
	{
		if (i > temp->nbr)
		{
			i = temp->nbr;
			temp_min = temp;
		}
		temp = temp->next;
	}
	return (temp_min);
}

t_node	*stack_max(t_node *stack_a)
{
	long		i;
	t_node		*temp;
	t_node		*temp_max;

	temp = stack_a;
	i = LONG_MIN;
	while (temp != NULL)
	{
		if (i < temp->nbr)
		{
			i = temp->nbr;
			temp_max = temp;
		}
		temp = temp->next;
	}
	return (temp_max);
}

// void	print_list(t_node **stack, char c)
// {
// 	t_node	*temp;

// 	temp = *stack;
// 	while (temp)
// 	{
// 		ft_printf("%i ", temp->nbr, c);
// 		temp = temp->next;
// 	}
// 	ft_printf("%c \n", c);
// 	ft_printf("%i -> list size\n", stack_size(*stack));
// }
