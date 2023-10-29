/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:34:42 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/10/26 23:22:07 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	exit_error(char *message, char **split)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	free_split(split);
	exit(0);
}