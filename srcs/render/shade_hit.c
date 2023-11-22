/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:35:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/22 19:43:13 by aqueiroz         ###   ########.fr       */
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
