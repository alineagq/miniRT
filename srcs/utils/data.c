/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:04:30 by fsuomins          #+#    #+#             */
/*   Updated: 2023/11/11 19:35:04 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

t_hit	*get_hit(void)
{
	static t_hit	hit;

	return (&hit);
}
