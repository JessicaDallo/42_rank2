#include "../../inc/push_swap.h"

int error_duplicate(t_node *list, int n)
{
	t_node *temp;

	temp = list-> head;
	if(temp == NULL)
		return (0);
	while (temp -> next != NULL)
	{
		if(temp -> nbr == n)
			return (1);
		temp = temp -> next;
	}
	return(0);
}

void free_list(t_node **list)
{
	t_node *temp;
	t_node *current;

	if(!list)
		return ;
	current = *list;
	while(current)
	{
		temp = current->next;
		current-> nbr = 0;
		free(current);
		current = temp;
	}
	*list = NULL;
}

void free_error(t_node **list)
{
	free_list(list);
	ft_printf("Error\n");
	exit (1);
}

int error_syntax(char *str)
{
	if(*str == '+' || *str == '-')
		str++;
	if(!(*str >= '0' && *str <= '9'))
		return (1);
	str++;
	while(*str != '\0')
	{
		if(!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}