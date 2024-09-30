/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:55:11 by marvin            #+#    #+#             */
/*   Updated: 2024/03/13 16:55:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>
// #include "stack_init.c"
// #include "errors_push.c"
// #include "../../libft/ft_printf.c"
// #include "../../libft/ft_split.c"
// #include "../../libft/ft_atol.c"
// #include "../../libft/ft_typedef.c"
// #include "../../libft/ft_putchar.c"
// #include "../../libft/ft_putstr.c"
// #include "../../libft/ft_putptr.c"
// #include "../../libft/ft_putint.c"
// #include "../../libft/ft_puthexa.c"
// #include "../../libft/ft_count_nbr.c"
// #include "../../libft/ft_putuns.c"
// #include "../../libft/ft_strchr.c"
// #include "../../libft/ft_strlen.c"
// #include "../../libft/ft_substr.c"
// #include "../../libft/ft_strdup.c"
// #include "../../libft/ft_strlcpy.c"

// int main()
// 	char *av[] = {"23", "5", "12", NULL};
// 	int ac = 3;

void sawp_stack(t_node *list, char letter)
{
	t_node *temp;
	int i = 0;
	if(!list)
		return;
	temp = list;
	i = temp->nbr;
	temp->nbr = temp->next->nbr;
	temp->next->nbr = i;
	ft_printf("s%c\n", letter);
}

void rra(t_node **list)
{
	if(!list)
		return;
	t_node *second_last = NULL;
	t_node *last = *list;

	while(last ->next != NULL)
	{
		second_last = last;
		last = last -> next;
	}
	second_last -> next = NULL;
	last -> next = *list;
	*list = last;
	ft_printf("rra\n");

}

void ra(t_node **list)
{
	if(!list)
		return;
	t_node *first = *list;
	t_node *last = *list;
	
	while (last -> next != NULL)
		last = last-> next;
	*list = first -> next;
	first -> next = NULL;
	last -> next = first;
	ft_printf("ra\n");
}

int	main(int ac, char **av)
{
	int i;
	t_node *list_a;
	t_node *temp;

	list_a = malloc(sizeof(t_node));
	if(!list_a)
		return (0);
	i = 1;
	if (ac == 1 || (ac == 2 && av[1][0]))
		return (1);
	while(i < ac)
	{
		init_list_a(list_a, av[i]);
		i++;
	}
	temp = list_a -> head;
	ra(&temp);
	sawap_stack(temp, a);
	rra(&temp);
	while (temp)
	{
		printf("%i ", temp->nbr);
		temp = temp -> next;
	}
	free_list(&list_a);
	return (0);
}