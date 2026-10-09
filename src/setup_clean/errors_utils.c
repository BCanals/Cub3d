/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 22:12:37 by bizcru            #+#    #+#             */
/*   Updated: 2026/10/09 21:06:21 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	print_emtpy_fc_error(t_line line_type)
{
	char	*msg;

	if (line_type == FLOOR)
		msg = "Floor texture: ";
	else
		msg = "Ceiling/sky texture: ";
	printf("%s%s%s", ERR, msg, RGB_EMPTY);
}

void	print_wrong_rgb_format(t_line line_type)
{
	char	*msg;

	if (line_type == FLOOR)
		msg = "Floor texture: ";
	else
		msg = "Ceiling/sky texture: ";
	printf("%s%s%s", ERR, msg, RGB_FORM_ERR);
}

void	print_emtpy_tex_error(t_line line_type)
{
	char	*(msgs[4]);

	msgs[0] = "NOrth texture: ";
	msgs[1] = "SOuth texture: ";
	msgs[2] = "EAst texture: ";
	msgs[3] = "WEst texture: ";
	printf("%s%s%s", ERR, msgs[line_type], TEX_EMPTY);
}

void	ft_error_msg(char *str, t_game *game)
{
	clean_t_game(game);
	printf("%s\n", str);
	exit(-1);
}
