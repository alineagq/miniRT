/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:43:05 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/30 22:39:41 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_atof(char *str)
{
	long double result;
	long double decimal;
	int sign;
	int i;

	result = 0;
	decimal = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		str++;
	while (*str && *str != '.')
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str)
	{
		decimal = decimal * 10 + (*str++ - '0');
		i++;
	}
	while (i-- > 0)
		decimal /= 10;
	result += decimal;
	return (result * sign);
}