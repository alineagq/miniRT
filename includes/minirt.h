/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/09 19:03:00 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "./structs.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define COLOR_NO "\033[m"
# define COLOR_RE "\033[0;31m"
# define COLOR_RE_1 "\033[1;31m"
# define COLOR_YE "\033[0;33m"
# define COLOR_YE_1 "\033[1;33m"
# define COLOR_GR "\033[0;32m"
# define COLOR_GR_1 "\033[1;32m"
# define COLOR_BL "\033[0;34m"
# define COLOR_BL_1 "\033[1;34m"
# define COLOR_PL "\033[0;35m"
# define COLOR_PL_1 "\033[1;35m"
# define COLOR_CY "\033[0;36m"
# define COLOR_CY_1 "\033[1;36m"
# define COLOR_WH "\033[0;37m"
# define WIDTH 1920
# define HEIGHT 1080
# define M_PI 3.14159265358979323846
# define M_INFINITY (1.0 / 0.0)

//////////////****** validation *******/////////////////////
int			validate_scene(char *file);
int			validate_resolution(char **line);
int			validate_ambient(char *line);
int			validate_camera(char *line);
int			validate_light(char *line);
int			validate_sphere(char *line);
int			validate_plane(char *line);
int			validate_cylinder(char *line);
int			validate_color(char *line, t_color *color);
int			validate_orientation(char *str1, char *str2, char *str3);
t_color		color_multiply(t_color color, double ratio);

//////////////****** structs *******/////////////////////
t_data		*get_data(void);

//////////////****** mlx *******/////////////////////
void		init_resolution(void);
void		window_loop(void);

//////////////****** vector *******/////////////////////
t_vector	vec_sub(t_vector v1, t_vector v2);
t_vector	vec_cross(t_vector v1, t_vector v2);
t_vector	vec_normalize(t_vector v);
t_vector	vec_add(t_vector v1, t_vector v2);

t_mat4		camera_show(t_vector origem, t_vector focus);

//////////////****** utils *******/////////////////////
void		free_split(char **split);
size_t		get_obj_size(t_shape_id id);
void		add_object(t_shape_id id, void *content);
void		remove_object(t_shape_id id);
void		clear_objects(void);
void		exit_error(char *message, char **split);

#endif