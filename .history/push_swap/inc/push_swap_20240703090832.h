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

typedef struct t_node
{
	int		nbr;
	struct t_node	*next;
	struct t_node	*head;
}	t_node;

typedef struct t_node_b
{
	int		nbr;
	struct t_node	*next;
	struct t_node	*head;
}	t_node_b;

t_node	*create_node(int nbr);

int		error_syntax(char *str);
int		main(int ac, char **av);
int		error_duplicate(t_node *list, int n);

void	swap_stack(t_node *list, char letter);
void	reverse_rotate(t_node **list, char letter);
void	rotate(t_node **list, char letter);
void	init_list_a(t_node *list, char *str);
void	free_list(t_node **list);
void	add_to_end_list(t_node *list, t_node *node);
void	free_error(t_node **list);

#endif
// handle error  
//stack initiation  
// nodes initiation  
//commands
//algorithms 