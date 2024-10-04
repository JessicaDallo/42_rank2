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
}

static void	cost_a(t_node *stack_a, t_node *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = list_size(&stack_a);
	size_b = list_size(&stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (stack_a->above_med == 0)
			stack_a->push_cost = size_a - (stack_a->index);
		if (stack_a->tag_node->above_med == 1)
			stack_a->push_cost = stack_a->tag_node->index;
		else
			stack_a->push_cost += size_b - (stack_a->tag_node->index);
		stack_a = stack_a->next;
	}
}

void	node_ind_a(t_node *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = list_size(stack) / 2;
	while(stack)
	{
		stack->index = index;
		if(index <= median)
			stack->above_med = 1;
		else 
			stack->above_med = 0;
		stack = stack->next;
		index++;
	}
}

void	tag_node_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*temp_b;
	t_node	*temp_tag;
	long 		better_index;

	while(stack_a)
	{
		better_index = LONG_MIN;
		temp_b = stack_b;
		while(stack_b)
		{
			if(temp_b->nbr < stack_a->nbr && temp_b->nbr > better_index)
			{
				better_index = temp_b->nbr;
				temp_tag = stack_b;
			}
			temp_b = temp_b->next;
		}
		if (better_index == LONG_MIN)
			stack_a->tag_node = list_max(stack_b);
		else
			stack_a->tag_node = temp_tag;
		stack_a = stack_a->next;
	}
}

void better_move(t_node *stack)
{
	long		cheap_nbr;
	t_node	*better_node;

	if (!stack)
		return ;
	cheap_nbr = LONG_MAX;
	while (stack)
	{
		if(stack->push_cost < cheap_nbr)
		{
			cheap_nbr = stack->push_cost;
			better_node = stack;
		}
		stack = stack -> next;
	}
	better_node->cheap = 1;
}

void	init_push_a(t_node *stack_a, t_node *stack_b)
{
	node_ind_a(stack_a);
	node_ind_a(stack_b);
	tag_node_a(stack_a, stack_b);
	cost_a(stack_a, stack_b);
	better_move(stack_a);
}

t_node	*get_better(t_node *stack)
{
	if(!stack)
		return(NULL);
	while (stack)
	{
		if(stack->cheap == 1)
			return(stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*better_node;

	better_node = get_better(*stack);
	if (better_node->above_med && (better_node->tag_node->above_med == 1))
	{//arrumar aqui colocoar um rotate both e um reverse rotate both
		rotate(stack_a);
		rotate(stack_b);
	}

}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	if(list_size(stack_a) > 5 && is_sorted(*stack_a) == 0)
		push(stack_a, stack_b, 'b');
	if(list_size(stack_a) > 5 && is_sorted(*stack_a) == 0)
		push(stack_a, stack_b, 'b');
	while(list_size(stack_a) > 5 && is_sorted(*stack_a) == 0)
	{
		init_push_a(*stack_a, *stack_b);
		a_to_b(stack_a, stack_b);
	}
}

void	push_swap(int ac, t_node **stack_a, t_node **stack_b)
{
	if (ac - 1 == 2)
		swap_two(*stack_a);
	else if (ac - 1 == 3)
		sort_three(stack_a);
	else if (ac - 1 <= 5)
		sort_five(stack_a, stack_b);
	else
		ordering(stack_a, stack_b);
	print_list(stack_a, 'a');
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (1);
	if (!error(ac, av, &stack_a) || av[1] == NULL)
	{
		free_list(&stack_a);
		ft_printf("Error");
		return (0);
	}
	if (is_sorted(stack_a) == 1)
	{
		ft_printf("ta ordenado");
		free_list(&stack_a);
		return (0);
	}
	push_swap(ac, &stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
