/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:24:08 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/01 13:19:14 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "structs.h"
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

int		validate_scene(char *file);
int		validate_ambient(char *line);
int		validate_camera(char *line);
int		validate_light(char *line);
int		is_numeric_string(const char *str);
int		validate_sphere(char *line);
int		validate_plane(char *line);
int		validate_cylinder(char *line);
int		validate_color(char *line);
void	exit_error(char *message, char **split);

//////////////****** parse *******/////////////////////

void	*parse_scene(const char *scene_file);
void	parse_ambient(const char *line, t_data *data);
void	parse_camera(const char *line, t_data *data);
void	parse_light(const char *line, t_data *data);
void	parse_sphere(const char *line, t_data *data);
void	parse_plane(const char *line, t_data *data);
void	parse_cylinder(const char *line, t_data *data);

void	free_split(char **split);
int		print_line_error(char *line);

#endif
