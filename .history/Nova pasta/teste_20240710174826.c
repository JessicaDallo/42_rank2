#include <stdio.h>
char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main(int ac, char **av)
{
	(void)ac;
	char *dest = '\0';
	dest = ft_strcpy(dest, av[1]);
	printf ("%s", dest);
}
