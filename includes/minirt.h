/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2024/03/16 15:13:39 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "../libs/libvector/libvector.h"
# include "definitions.h"
# include "hit.h"
# include "objects.h"
# include "render.h"
# include "scene.h"
# include "validate.h"
# include "window.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	t_mlx		mlx;
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_object	*objects;
}				t_data;

// Utils
t_data			*get_data(void);
void			print_header(void);
void			print_data(void);

#endif
