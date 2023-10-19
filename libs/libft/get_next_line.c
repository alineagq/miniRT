/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:46:38 by coder             #+#    #+#             */
/*   Updated: 2023/10/18 21:41:19 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	int i = 0;
	int read_line = 0;
	char character;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	char *buffer = malloc(100000);
	while ((read_line = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE
				+ 1)) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (read_line == -1 || i == 0 || (!buffer[i - 1] && !read_line))
		return (free(buffer), NULL);
	return (buffer);
}
