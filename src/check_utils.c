/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:06:27 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/06 10:06:29 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_col_play_exit(t_game *game)
{
	int	player;
	int	col;
	int	exit;

	player = 0;
	col = 0;
	exit = 0;
	count_col_play_exit(game, &player, &col, &exit);
	validate_col_play_exit(game, player, col, exit);
}

void	count_col_play_exit(t_game *game, int *player, int *col, int *exit)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
				(*player)++;
			else if (game->map[y][x] == 'C')
			{
				(*col)++;
				game->collectibles = *col;
			}
			else if (game->map[y][x] == 'E')
				(*exit)++;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				map_error(game, "Invalid character.");
			x++;
		}
		y++;
	}
}

void	validate_col_play_exit(t_game *game, int player, int col, int exit)
{
	if (player != 1)
		map_error(game, "There must be 1 player.");
	if (col < 1)
		map_error(game, "There must be at least one collectible.");
	if (exit != 1)
		map_error(game, "There must be 1 exit.");
}
