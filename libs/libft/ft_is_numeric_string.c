/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:59:11 by fsuomins          #+#    #+#             */
/*   Updated: 2024/03/16 01:16:19 by aqueiroz         ###   ########.fr       */
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
