/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 18:31:47 by becanals          #+#    #+#             */
/*   Updated: 2026/09/26 12:09:18 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static int	check_file_ext(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	if (ft_strcmp(&file_name[len - 4], ".cub"))
		return (0);
	return (1);
}

int	parser(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	**buffer;

	if (argc < 2)
		return (printf("Usage: %s [map]\n", argv[0]), 0);
	if (!check_file_ext(argv[1]))
		return (printf("The scene file must be in '*.cub' format\n"), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error on open: %s\n", strerror(errno)), 0);
	buffer = ft_calloc(sizeof(char *), 1);
	line = get_next_line(fd, buffer);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd, buffer);
	if (line)
		printf("%s\n", line);
	free(*buffer);
	free(buffer);
	return (printf("Tot en ordre de moment!\n"), 1);
}
