/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:15:14 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/08 09:18:37 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4 || strcmp(str + len - 4, ".ber") != 0)
		error_exit("The map must be a file with a .ber extension.");
}

void	check(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			map_error(game, "Invalid map!");
		x++;
	}
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			map_error(game, "Invalid map!");
		y++;
	}
	check_lines_columns(game);
	check_valid_char(game);
	check_col_play_exit(game);
}

void	check_lines_columns(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
			map_error(game, "All the lines must measure the same.");
		i++;
	}
}

void	check_valid_char(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] != 'E' && game->map[y][x] != 'C'
				&& game->map[y][x] != 'P' && game->map[y][x] != '0'
				&& game->map[y][x] != '1')
			{
				map_error(game, "Invalid character!");
			}
			x++;
		}
		y++;
	}
}
