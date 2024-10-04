/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:54:40 by marvin            #+#    #+#             */
/*   Updated: 2024/03/13 16:54:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				number;
	int				size;
	struct s_node	*next;
	struct s_node	*head;

}t_node;

// typedef struct stack_list
// {
// 	
// } stack_list;

//int	main();
t_node	*create_node(int number);

int		main(int ac, char **av);
int		error_syntax(char *str);
int		error_duplicate(t_node *list, int n);

void	add_to_end_list(t_node *list, t_node *node);
void	init_list_a(t_node *list, char *str);
void	free_error(t_node **list);
void	free_list(t_node **list);

#endif
// handle error ok
//stack initiation ok  
// nodes initiation  ok 
//commands
//algorithms 