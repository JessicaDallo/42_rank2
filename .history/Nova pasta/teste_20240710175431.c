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

int main()
{
	
	char src [] = "amora";
	char dest []= '\0';
	printf("%s\n", dest);
	ft_strcpy (dest ,src);
	printf("%s\n", dest);
	
	return (0);
	
}
