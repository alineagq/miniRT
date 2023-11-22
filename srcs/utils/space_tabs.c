/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_tabs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:31:32 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/20 19:31:55 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	removeDoubleSpacesAndTabs(char *str)
{
	int	len;

	int i, j;
	len = strlen(str);
	for (i = 0, j = 0; i < len; i++)
	{
		if (!(str[i] == ' ' && str[i + 1] == ' ') && str[i] != '\t')
			str[j++] = str[i];
	}
	str[j] = '\0';
}
