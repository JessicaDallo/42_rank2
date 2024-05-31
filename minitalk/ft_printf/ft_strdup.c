/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:24:13 by jessicadall       #+#    #+#             */
/*   Updated: 2024/03/31 21:21:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// copia uma string para outra, mas com alocação de memoria correta
char	*ft_strdup(char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
// int main (void)
// {
// 	char *result;
// 	char word[] = "jessica";
// 	result = ft_strdup(word);
// 	printf("%s", result);
// }