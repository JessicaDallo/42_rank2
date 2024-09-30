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


s_stack *create_node(s_stack *list, int nbr)
{
	s_stack *node;

	node = malloc(sizeof(s_stack));
	if(!node)
		return (NULL);
	node -> nbr = nbr;
	node -> next = NULL;
	return (node);
}

int	main(int ac, char **av)
{
	s_stack *list_a;
	s_stack *temp;
	s_stack	*node;
	int i = 0;
	long nbr;
	
	list_a = malloc(sizeof(s_stack));
	temp = list_a;
	while (++i < ac)
	{
		ft_printf("%s\n", av[i]);
		nbr = (atol(av[i]));
		node = create_node(list_a, nbr);
	}
	list_a = temp;
	int j = 0;
	while (temp)
	{
		temp = temp -> next;
		j++;
	}
		ft_printf("%i quantos nodes\n ", j);
	while(node -> next != NULL)
	{
		ft_printf("%i", node -> nbr);
		node = node -> next;
	}

	
	return (0);
}
