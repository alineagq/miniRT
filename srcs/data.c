/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:20:00 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/10/30 20:35:25 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	free_data(void)
{
	// t_data	*data;

	// data = get_data();
}
