#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

static int g_size = 0;

char	*ft_printffree(char *str)
{
	str[g_size] = '\0';
	ft_printf("MESSAGE: %s\n", str);
	free (str);
	//ft_printf(" ANTES DO FREE %i\n", g_size);
	g_size = 0;
	//ft_printf(" DEPOIS DO FREE %i\n", g_size);
	return (NULL);
}

char	*ft_create(int size)
{
	char *str = NULL;
	str = (char*)malloc(size * sizeof(char) + 1);
	if (!str)
	{
	//	free (str);
		return (NULL);
	}
	ft_printf("o que tem aqui?");
	return (str);
}

void handler_size(int sig)
{
	static int	size = 0;
	static int bitcount = 0;
	
	if (sig == SIGUSR2)	
		size = size << 1;
	else
		size = (size << 1) | 1;
	bitcount++;

	if (bitcount == 32)
	{
		g_size = size;
		ft_printf("Received size: %i\n", g_size);
		bitcount = 0;
		size = 0;
	}
}

void handler_message(int sig)
{
	static int	j = 0;
	static char	c = 0;
	static int	i = 0;
	static char *str = NULL;

	if (sig == SIGUSR2)	
		c = c << 1;
	else
		c = (c << 1) | 1;
	i++;
	if (i == 8)
	{
		if (str == NULL)
			str = ft_create(g_size);
		str[j] = c;
		j++;
		i = 0;
		c = 0;
	}
	if (j == g_size)
	{
		j = 0;
		str = ft_printffree(str);
	}
}

int main()
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		if (g_size == 0)
		{		
			signal(SIGUSR1, handler_size);
			signal(SIGUSR2, handler_size);
			//pause ();
		}
		else 
		{			
			signal(SIGUSR1, handler_message);
			signal(SIGUSR2, handler_message);
			//pause ();
		}
	}
}
// int main() 
// {
//     struct sigaction sa_size;
//     struct sigaction sa_message;

//     sa_size.sa_handler = handler_size;
//     sa_size.sa_flags = 0;
//     sigemptyset(&sa_size.sa_mask);

//     sa_message.sa_handler = handler_message;
//     sa_message.sa_flags = 0;
//     sigemptyset(&sa_message.sa_mask);

//     printf("PID: %d\n", getpid());

//     while (1) {
//         if (g_size == 0) {
//             sigaction(SIGUSR1, &sa_size, NULL);
//             sigaction(SIGUSR2, &sa_size, NULL);
//         } else {
//             sigaction(SIGUSR1, &sa_message, NULL);
//             sigaction(SIGUSR2, &sa_message, NULL);
//         }
//         pause();
//     }
// }

