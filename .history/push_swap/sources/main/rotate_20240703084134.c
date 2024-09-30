#include "../../inc/push_swap.h"

void reverse_rotate(t_node **list, char letter)
{
	if(!list)
		return;
	t_node *second_last = NULL;
	t_node *last = *list;

	while(last ->next != NULL)
	{
		second_last = last;
		last = last -> next;
	}
	second_last -> next = NULL;
	last -> next = *list;
	*list = last;
	ft_printf("rr%c\n", letter);

}

void rr(t_node *list_a, t_node *list_b)
{
	t_node *first;
	t_node *last;

	if(!list_a ||!list_b || !list_a->next || !list_b->next)
		return ;
	*first = *list_a;
	*last = *list_a;
	while (last->next != NULL)
		last = last -> next;
	list_a = first -> next ;
	first -> next = NULL;
	last -> next = first;
	*first = *list_b;
	*last = *list_b;
	while (last->next != NULL)
		last=last->next;
	list_b = first -> next;
	first -> next = NULL;
	last -> next = first;
	printf("rr\n");
}

void rotate(t_node **list, char letter)
{
	if(!list)
		return ;
	t_node *first = *list;
	t_node *last = *list;
	
	while (last -> next != NULL)
		last = last-> next;
	*list = first -> next;
	first -> next = NULL;
	last -> next = first;
	ft_printf("r%c\n", letter);
}
