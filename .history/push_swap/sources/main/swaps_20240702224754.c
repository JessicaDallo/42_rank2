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

void sswap(t_node *list_a, t_node *list_b)
{
	t_node *temp;
	int i = 0;
	if (!list_a || !list_b || !list_a->next || !list_b -> next)
		return ;
	temp = list_a -> nbr;
	list_a-> nbr = list_a->next->nbr;
	list_a->next->nbr = temp;
	temp = list_b ->nbr;
	list_b->nbr = list_b->next->nbr;
	list_b->next->nbr = temp;
	printf("ss\n");
}