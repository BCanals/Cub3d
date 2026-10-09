/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 22:09:21 by bizcru            #+#    #+#             */
/*   Updated: 2026/10/09 20:58:31 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static int	load_rgb_param(char *str, t_parser *data, int loop)
{
	unsigned int	read;

	read = *str - '0';
	str++;
	while (ft_isdigit(*str))
	{
		read *= 10;
		read += *str - '0';
		str++;
	}
	if (read > 255)
		return (0);
	if (data->line_type == FLOOR)
		((unsigned char*)&data->game->map.floor)[loop] = (unsigned char) read;
	else
		((unsigned char*)&data->game->map.sky)[loop] = (unsigned char) read;
	return (1);
}

static int	load_rgb(t_parser *parser, char *str)
{
	int	loop;
	int	i;

	loop = -1;
	while (++loop < 3)
	{
		i = 0;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (i < 1 || i > 3)
			return (0);
		if (!load_rgb_param(str, parser, loop))
			return (0);
		str += i;
		if (loop < 2 && !*str)
			return (0);
		if (loop < 2 && *str != ',')
			return (0);
		else
			str++;
	}
	return (1);
}

int	parse_fc(t_parser *data)
{
	char	*tmp;

	tmp = data->line;
	while (*tmp && *tmp == ' ')
		tmp++;
	tmp += 2;
	while (*tmp && *tmp == ' ')
		tmp++;
	if (!*tmp || *tmp == '\n')
		return (print_emtpy_fc_error(data->line_type), 0);
	if (!load_rgb(data, tmp))
		return (print_wrong_rgb_format(data->line_type), 0);
	return (1);
}

static void	wall_point_to_start(char **tmp)
{
	while (**tmp && **tmp == ' ')
		(*tmp)++;
	*tmp += 3;
	while (**tmp && **tmp == ' ')
		(*tmp)++;
}

int	parse_wall(t_parser *data)
{
	char	*endl;
	char	*tmp;

	tmp = data->line;
	wall_point_to_start(&tmp);
	if (!*tmp || *tmp == '\n')
		return (print_emtpy_tex_error(data->line_type), 0);
	endl = ft_strchr(tmp, '\n');
	if (endl)
		*endl = 0;
	tmp = ft_strdup(tmp);
	if (!tmp)
		return (printf("%s%s", ERR, MALL_ERR), 0);
	if (data->line_type == TEX_N)
		data->game->map.no = tmp;
	if (data->line_type == TEX_S)
		data->game->map.so = tmp;
	if (data->line_type == TEX_E)
		data->game->map.ea = tmp;
	if (data->line_type == TEX_O)
		data->game->map.we = tmp;
	return (1);
}
