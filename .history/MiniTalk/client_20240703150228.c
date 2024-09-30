#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

void	send_size(int pid, int size)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (size & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i--;
	}
}

void	send_message(int pid, char *str, int size)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (i < size)
	{
		x = 8;
		while (x > 0)
		{
			if (str[i] & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			ft_printf("*");
			str[i] = str[i] << 1;
			x--;
			usleep(50);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*str;
	int		pid;
	int		len;

	if (ac != 3)
	{
		ft_printf("Please try again with the corrects informations. \n");
		ft_printf("./client <PID number> <message>");
		return (0);
	}
	str = av[2];
	len = 0;
	len = ft_strlen(str);
	pid = ft_atoi(av[1]);
	ft_printf("%d\n", len);
	send_size(pid, len);
	send_message(pid, str, len);
	return (0);
}
