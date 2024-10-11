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
	struct t_node	*prev;
}	t_node;

t_node	*create_stack(char *num);
struct t_node	init_stack(t_node **stack, char **av);

//algorithm
//ordering.c
void		min_top(t_node **stack_a);
void		b_to_a(t_node **stack_a, t_node **stack_b);
void		a_to_b(t_node **stack_a, t_node **stack_b);
void		ordering(t_node **stack_a, t_node **stack_b);

//a_to_b.c
void		cost_a(t_node *stack_a, t_node *stack_b);
void		tag_node_a(t_node *stack_a, t_node *stack_b);
void		init_push_a(t_node *stack_a, t_node *stack_b);

//b_to_a.c
void		tag_node_b(t_node *stack_a, t_node *stack_b);
void		init_push_b(t_node *stack_a, t_node *stack_b);

//ordering_utils.c
void		better_move(t_node *stack);
void		node_ind(t_node *stack);
t_node		*get_better(t_node *stack);
void		pre_push(t_node **stack, t_node *top_node, char letter);

//main
int		main(int ac, char **av);
void		push_swap(int ac, t_node **stack_a, t_node **stack_b);
void		print_list(t_node **stack, char c);

//errorr_push.c
int		error_size(char **av);
int		error_syntax(char **av);
int		error_duplicate(char **av);
int		error(int ac, char **av, t_node **stack_a);
int		verif_error(char **av);
//stack_utils.c
int		stack_size(t_node *stack);
t_node		*stack_min(t_node *stack_a);
t_node		*stack_max(t_node *stack_a);

//stack_init.c
void		add_to_end_stack(t_node *stack, char *num);
void		free_stack(t_node **stack);
t_node		init_stack(t_node **stack, char **av);
t_node		*create_stack(char *str);
void		free_initial_array(char **initial);//preciso disso?

//commands
//rev_rotates.c
void		rev_rotate(t_node **stack, char c);
void		rev_rotate_both(t_node **a, t_node **b, t_node *better);

//rotates.c
void		rotate(t_node **stack, char c);
void		rotate_both(t_node **a, t_node **b, t_node *better);

//push.c
void		push(t_node **dest, t_node **src, char c);

//swap_moves.c
void		swap(t_node **stack, char c);
void		swap_both(t_node **stack_a, t_node **stack_b);

//sorted.c
void		sort_five(t_node **stack_a, t_node **stack_b);
void		sort_three(t_node **stack_a);
int		is_sorted(t_node *stack_a);

# endif
// handle error  
//stack initiation  
// nodes initiation  
//commands
//algorithms 