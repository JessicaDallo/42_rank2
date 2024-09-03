/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:29:16 by marvin            #+#    #+#             */
/*   Updated: 2023/10/28 17:29:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *input, ...)
{
	va_list	list_arg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(list_arg, input);
	while (input[j])
	{
		if (input[j] == '%')
		{
			i = i + ft_typedef(list_arg, input[j + 1]);
			j++;
		}
		else
			i = i + ft_putchar(input[j]);
		j++;
	}
	va_end (list_arg);
	return (i);
}
