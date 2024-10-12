#include "../../inc/push_swap.h"

int	error_duplicate(char **av)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error(int ac, char **av, t_node **stack_a)
{
	char	**initial;
	size_t	i;

	initial = NULL;
	i = 0;
	if (ac == 2)
		initial = ft_split(av[1], ' ');
	else if (ac > 2)
		av++;
	if (!initial && verif_error(av) == 0)
		init_stack(stack_a, av);
	else if (initial && verif_error(initial) == 0)
		init_stack(stack_a, initial);
	if (initial)
	{
		while (initial[i])
		{
			free(initial[i]);
			i++;
		}
		free(initial);
	}
	if (!stack_a || !(*stack_a))
		return (0);
	return (1);
}

int	error_syntax(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && ((av[i][j] == '-') || av[i][j] == '+'))
				j++;
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_size(char **av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	verif_error(char **av)
{
	if (av == NULL || av[0] == NULL)
		return (0);
	if ((error_syntax(av) || error_size(av) || error_duplicate(av)) == 1)
	{
		return (1);
	}
	return (0);
}
