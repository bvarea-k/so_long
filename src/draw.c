/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:40:26 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/07 11:40:29 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->img_player,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

void	render_tile(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	mlx_image_to_window(game->mlx, game->img_background,
		x * TILE_SIZE, y * TILE_SIZE);
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->img_wall, px, py);
	else if (game->map[y][x] == '0')
		mlx_image_to_window(game->mlx, game->img_background, px, py);
	else if (game->map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->img_player, px, py);
	else if (game->map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->img_collect, px, py);
	else if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->img_exit, px, py);
	else
		mlx_image_to_window(game->mlx, game->img_background, px, py);
}
