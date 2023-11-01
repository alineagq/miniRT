/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:04:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/01 14:04:51 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

// void	free_data(void)
// {
// 	// t_data	*data;

// 	// data = get_data();
// }