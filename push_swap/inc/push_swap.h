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
	int		index;
	int		push_cost;
	int		above_med;
	int		cheap;
	struct t_node	*tag_node;
	struct t_node	*next;
	struct t_node	*head;
}	t_node;

t_node	*create_stack(char *num);
struct t_node	init_stack(t_node **stack, char **av);

int		main(int ac, char **av);
//error
int		error_size(char **av);
int		error_syntax(char **av);
int		error_duplicate(char **av);
int		error(int ac, char **av, t_node **stack_a);
int		verror(char **av);
//utils
int		is_sorted(t_node *list);
int		list_size(t_node **stack);
int		list_min(t_node **stack_a);
int		list_max(t_node **stack_a);
//init stacks
void	add_to_end_stack(t_node *stack, char *num);
void	free_error(t_node **list);
void	free_list(t_node **list);
//moves
void	push(t_node **stack_1, t_node **stack_2, char c);
void	swap_two(t_node *list);
void	rotate(t_node **list, char letter);
void	swap_stack(t_node *list, char letter);
void	reverse_rotate(t_node **list, char letter);
//ordenation
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **list);
void	sort_stack(t_node **stack_a, t_node **stack_b);


#endif
// handle error  
//stack initiation  
// nodes initiation  
//commands
//algorithms 