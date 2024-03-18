/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:43:05 by fsuomins          #+#    #+#             */
/*   Updated: 2024/01/31 21:39:41 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	decimal;
	double	decimal_sign;

	result = 0;
	sign = 1;
	decimal = 0;
	decimal_sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			decimal = decimal * 10 + (*str - '0');
			decimal_sign *= 10;
			str++;
		}
	}
	return (sign * (result + decimal / decimal_sign));
}
