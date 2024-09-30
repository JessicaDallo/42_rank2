#include "../../inc/push_swap.h"

void	reverse_rotate(t_node **list, char letter)
{
	t_node	*second_last;
	t_node	*last;

	if (!list)
		return ;
	second_last = NULL;
	last = list;
	while (last ->next != NULL)
	{
		second_last = last;
		last = last -> next;
	}
	second_last -> next = NULL;
	last -> next = *list;
	*list = last;
	ft_printf("rr%c\n", letter);
}

void	rr(t_node **list_a, t_node **list_b)
{
	t_node	*first_a;
	t_node	*first_b;
	t_node	*last_a;
	t_node	*last_b;

	if (!list_a ||!list_b)
		return ;
	first_a = list_a;
	first_b = list_b;
	last_a = list_a;
	last_b = list_b;
	while (last_a->next != NULL)
		last_a = last_a -> next;
	list_a = first_a -> next ;
	first_a -> next = NULL;
	last_a -> next = first_a;
	while (last_b->next != NULL)
		last_b = last_b->next;
	list_b = first_b -> next;
	first_b -> next = NULL;
	last_b -> next = first_b;
	printf("rr\n");
}

void	rotate(t_node **list, char letter)
{
	t_node	*last;
	t_node	*first;
	
	if (!list)
		return ;
	first = list;
	last = list;
	while (last -> next != NULL)
		last = last-> next;
	*list = first -> next;
	first -> next = NULL;
	last -> next = first;
	ft_printf("r%c\n", letter);
}
