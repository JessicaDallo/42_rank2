#include "../../inc/push_swap.h"

void	swap_stack(t_node *list, char letter)
{
	int		i;
	t_node	*temp;

	if (!list)
		return;
	i= 0;
	temp = list;
	i = temp->nbr;
	temp->nbr = temp->next->nbr;
	temp->next->nbr = i;
	ft_printf("s%c\n", letter);
}

void	sswap(t_node *list_a, t_node *list_b)
{
	int		i;
	t_node	*temp;

	if (!list_a || !list_b || !list_a->next || !list_b -> next)
		return ;
	i = 0;
	temp = list_a -> nbr;
	list_a-> nbr = list_a->next->nbr;
	list_a->next->nbr = temp;
	temp = list_b ->nbr;
	list_b->nbr = list_b->next->nbr;
	list_b->next->nbr = temp;
	printf("ss\n");
}