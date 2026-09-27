/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 18:31:47 by becanals          #+#    #+#             */
/*   Updated: 2026/09/27 23:31:46 by bizcru           ###   ########.fr       */
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
/*
static int	load_scene(t_parser *data)
{
	while
}
*/
int	parser(int argc, char **argv)
{
	t_parser	p_data;

	if (argc < 2)
		return (printf("Usage: %s [map]\n", argv[0]), 0);
	if (!check_file_ext(argv[1]))
		return (printf("The scene file must be in '*.cub' format\n"), 0);
	if (!load_t_parser(&p_data, argv[1]))
		return (0);
	//if (!load_scene(&p_data))
	//	return (0);

	
	p_data.line = get_next_line(p_data.fd, &p_data.buffer);
	printf("%s\n", p_data.line);
	
	clean_t_parser(&p_data);
	return (printf("Tot en ordre de moment!\n"), 1);
}
