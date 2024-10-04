
#include "../../inc/push_swap.h"

void	swap_stack(t_node *list, char letter)
{
	int	temp;

	if (!list)
		return ;
	temp = list -> nbr;
	list -> nbr = list -> next -> nbr;
	list -> next -> nbr = temp;
	ft_printf("s%c\n", letter);
}

void	swap_two(t_node *list)
{
	if (!list)
		return ;
	swap_stack(list, 'a');
	return ;
}
