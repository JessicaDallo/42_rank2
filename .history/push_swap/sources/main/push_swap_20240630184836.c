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

void free_list(t_node **list)
{
	t_node *temp;
	t_node *current;

	if(!list)
		return ;
	current = *list;
	while(current)
	{
		temp = current->next;
		current-> nbr = 0;
		free(current);
		current = temp;
	}
	*list = NULL;
}

void free_error(t_node **list)
{
	free_list(list);
	ft_printf("Error\n");
	exit (1);
}

int error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if((*str == '+' || *str == '-') && (!(*str >= '0' && *str <= '9')))
		return (1);
	str++;
	while(*str != '\0')
	{
		if(!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

void add_to_end_list(t_node *list, t_node *node)
{
	t_node *temp;

	if(list -> head == NULL)
	{
		list -> head = node;
		node -> next = NULL;
		return ;
	}
	else 
	{
		temp = list -> head;
		while (temp -> next != NULL)
			temp = temp -> next;
	}
	temp -> next = node;
	node -> next = NULL;
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

void init_list_a(t_node *list, char *str)
{
	char **initial;
	t_node *node;
	long n;

	initial = ft_split(str, ' ');
	if(initial != NULL)
	{
		while(*initial)
		{
			if(error_syntax(*initial))
				free_error(&list->head);
			n = atol(str);
			if(n > INT_MAX || n < INT_MIN)
				free_error(&list->head);
			node = create_node(n);
			add_to_end_list(list, node);
			if(error_duplicate(list, n) != 0)
				free_error(&list->head);
			initial++;
		}
	}
	
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
		return (0);
	while(i < ac)
	{
		init_list_a(list_a, av[i]);
		i++;
	}
	temp = list_a -> head;
	while (temp)
	{
		printf("%i ", temp->nbr);
		temp = temp -> next;
	}
	//free_list(list_a);
	return (0);
}