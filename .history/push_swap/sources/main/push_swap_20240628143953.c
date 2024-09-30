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


s_stack *create_node(int nbr)
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
	t_node *list_a = NULL;
	t_node *temp = NULL;
	int i = 1;
	int nbr = 0;

	while(i < ac)
	{
		nbr = atol(av[i]);
		list_a = create_node(nbr);
		if(!list_a)
			return (0);
		if (list_a == NULL)
			temp = list_a;
		list_a = list_a -> next;
		i++;
	}
	list_a = temp;
	while (temp)
	{
		printf("%i ", temp->nbr);
		temp = temp -> next;
	}
	return (0);
}