#include <stdio.h>
char	*ft_strcpy(const char *dest, const char *src)
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

int main(void)
{
	
	char src [] = "amora";
	char dest []= "..";
	printf("%s\n", dest);
	ft_strcpy (dest ,src);
	printf("%s\n", dest);
	
	return (0);
	
}
