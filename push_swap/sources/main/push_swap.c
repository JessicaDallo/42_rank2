/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <jesilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:55:11 by jesilva-          #+#    #+#             */
/*   Updated: 2024/03/13 16:55:11 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_list(t_node **stack, char c)
{
	t_node	*temp;

	temp = *stack;
	while (temp)
	{
		ft_printf("%i ", temp->nbr, c);
		temp = temp->next;
	}
	ft_printf("%c \n", c);
	ft_printf("%i -> list size\n", stack_size(*stack));
}


void	push_swap(int ac, t_node **stack_a, t_node **stack_b)
{
	(void)ac;
	if (stack_size(*stack_a) == 2)
		swap(stack_a, 'a');
	else if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	else if (stack_size(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else
		ordering(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (!error(ac, av, &stack_a) || av[1] == NULL)
	{
		free_stack(&stack_a);
		ft_printf("Error");
		return (0);
	}
	if (is_sorted(stack_a) == 1)
	{
		free_stack(&stack_a);
		return (0);
	}
	push_swap(ac, &stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
