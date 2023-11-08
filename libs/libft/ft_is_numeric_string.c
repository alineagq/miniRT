/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:59:11 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/07 22:00:24 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_numeric_string(const char *str)
{
	int	dot_found;

	if (*str == '\0')
		return (0);
	if (*str == '-')
		str++;
	dot_found = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else if (*str == '.' && !dot_found)
		{
			dot_found = 1;
			str++;
		}
		else if (*str == '\n')
			return (1);
		else
			return (0);
	}
	return (1);
}
