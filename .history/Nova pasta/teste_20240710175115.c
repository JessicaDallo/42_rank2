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
	
	char *result = ft_strcpy(result, av[1]);
	printf ("%s", result);
}
