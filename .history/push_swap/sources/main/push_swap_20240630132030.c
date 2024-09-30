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


void init_list_a(t_node list, char *str)
{
	t_node *node;
	long n;

	n = atol(str);
	node = create_node(n);
	if(!node)
		return (0);
	if (!list)
		list = node;
	else 
		temp -> next = node; 
	temp = node;
	i++;
}

t_node *create_node(int nbr)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if(!node)
		return (NULL);
	node -> nbr = nbr;
	node -> next = NULL;
	return (node);
}

int	main(int ac, char **av)
{
	int i;
	t_node *list_a = NULL;
	t_node *temp = NULL;

	list_a = malloc(sizeof(t_node));
	if(!list_a)
		return (0);
	i = 1;
	if (ac == 1 || (ac == 2 && av[1][0]))
		return (0);
	while(i < ac)
	{
		init_list_a(list_a, av[i]);
	}
	temp = list_a -> head;
	while (temp)
	{
		printf("%i ", temp->nbr);
		temp = temp -> next;
	}
	free_list(list_a);
	return (0);
}