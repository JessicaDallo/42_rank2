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
	free(second_last);

}

void rotate(t_node **list, char letter)
{
	if(!list)
		return;
	t_node *first = *list;
	t_node *last = *list;
	
	while (last -> next != NULL)
		last = last-> next;
	*list = first -> next;
	first -> next = NULL;
	last -> next = first;
	ft_printf("r%c\n", letter);
	free(last);
}
