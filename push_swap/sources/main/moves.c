#include "../../inc/push_swap.h"

void	reverse_rotate(t_node **list, char letter)
{
	t_node	*second_last;
	t_node	*last;

	last = *list;
	second_last = NULL;
	if (!list)
		return ;
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

void	rotate(t_node **list, char letter)
{
	t_node	*last;
	t_node	*first;

	last = *list;
	first = *list;
	if (!list)
		return ;
	while (last -> next != NULL)
		last = last-> next;
	*list = first -> next;
	first -> next = NULL;
	last -> next = first;
	ft_printf("r%c\n", letter);
}

void	push(t_node **stack_1, t_node **stack_2, char c)
{
	t_node	*temp;

	if (*stack_1)
	{
		temp = *stack_1;
		*stack_1 = (*stack_1)->next;
		temp->next = *stack_2;
		*stack_2 = temp;
	}
	if (c == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
