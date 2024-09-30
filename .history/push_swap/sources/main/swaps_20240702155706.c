#include "../../inc/push_swap.h"

void swap_stack(t_node *list, char letter)
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