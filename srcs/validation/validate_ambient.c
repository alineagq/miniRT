/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:14:05 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/18 10:18:51 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	validate_ambient_color(char **ambient)
{
    int		i;
    char	**color;

    i = 0;
    while (ambient[i])
    {
        color = ft_split(ambient[i], ',');
        if (ft_strslen(color) != 3)
        {
            ft_free_split(color);
            return (0);
        }
        if (!validate_color(color))
        {
            ft_free_split(color);
            return (0);
        }
        ft_free_split(color);
        i++;
    }
    return (1);
}

