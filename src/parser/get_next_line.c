/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:22:49 by bcanals-          #+#    #+#             */
/*   Updated: 2026/09/24 19:50:15 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static char	*gnl_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*gnl_next(char *buffer, char *line)
{
	char	*new_buffer;
	size_t	buf_len;
	size_t	line_len;

	line_len = ft_strlen(line);
	buf_len = ft_strlen(buffer) - line_len;
	new_buffer = ft_calloc(buf_len + 1, 1);
	if (!new_buffer)
		return (gnl_free(&line), gnl_free(&buffer));
	new_buffer = ft_memcpy(new_buffer, buffer + line_len, buf_len);
	gnl_free(&buffer);
	return (new_buffer);
}

static char	*gnl_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, 1);
	if (!line)
		return (gnl_free(&line));
	ft_memcpy(line, buffer, i);
	return (line);
}

static char	*gnl_read(int fd, char *buffer)
{
	char	*reading;
	int		read_bytes;

	while (!ft_strchr(buffer, '\n'))
	{
		reading = ft_calloc(42 + 1, 1);
		if (!reading)
			return (NULL);
		read_bytes = read(fd, reading, 42);
		if (read_bytes < 0)
			return (gnl_free(&reading), gnl_free(&buffer));
		else if (read_bytes == 0)
		{
			gnl_free(&reading);
			return (buffer);
		}
		buffer = ft_strjoin(buffer, reading);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || 42 <= 0)
	{
		if (buffer)
			gnl_free(&buffer);
		return (NULL);
	}
	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (gnl_free(&buffer));
	buffer = gnl_read(fd, buffer);
	if (!buffer)
		return (NULL);
	if (!*buffer)
		return (gnl_free(&buffer));
	line = gnl_line(buffer);
	if (!line)
		return (gnl_free(&buffer), gnl_free(&line));
	buffer = gnl_next(buffer, line);
	if (!buffer)
		return (gnl_free(&buffer));
	return (line);
}
