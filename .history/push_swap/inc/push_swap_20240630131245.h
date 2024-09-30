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
	int nbr;
	struct t_node *next;
	struct t_node *head;	
} t_node;

int	main(int ac, char **av);

#endif
// handle error  
//stack initiation  
// nodes initiation  
//commands
//algorithms 