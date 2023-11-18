/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:34:06 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/18 15:34:21 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	print_line_error(char *line)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid line: ", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}