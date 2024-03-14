/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:35:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/13 20:10:51 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vector	shade_hit(t_comps comps)
{
	t_vector	color;
	int			shadowed;

	shadowed = is_shadowed(comps.over_point);
	color = lighting(get_data()->light, comps, get_data()->ambient, shadowed);
	return (color);
}
