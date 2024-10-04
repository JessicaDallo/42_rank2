#include "../../inc/push_swap.h"

void	add_to_end_stack(t_node *stack, char *num)
{
	t_node	*temp;

	temp = create_stack(num);
	while (stack->next != NULL)
		stack = stack->next;
	stack->next = temp;
}

t_node	*create_stack(char *str)
{
	int		num;
	t_node	*node;

	num = ft_atol(str);
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node -> nbr = num;
	node -> next = NULL;
	return (node);
	free(node);
}

struct t_node	init_stack(t_node **stack, char **av)
{
	size_t	i;

	i = 1;
	*stack = create_stack(av[0]);
	while (av[i])
	{
		add_to_end_stack(*stack, av[i]);
		i++;
	}
	return (**stack);
}

void	free_initial_array(char **initial)
{
	int	i;

	i = 0;
	while (initial[i])
	{
		free(initial[i]);
		i++;
	}
	free(initial);
}

void	free_list(t_node **list)
{
	t_node	*temp;
	t_node	*current;

	if (!list)
		return ;
	current = *list;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*list = NULL;
}
