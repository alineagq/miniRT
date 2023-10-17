/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/10/17 10:35:46 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "structs.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"


void	exit_error(char *message);
void	validate_scene(char *file);
void	validate_ambient(char *line);
void	validate_camera(char *line);
void	validate_light(char *line);
void	validate_sphere(char *line);
void	validate_plane(char *line);
void	validate_cylinder(char *line);

#endif