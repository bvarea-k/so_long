/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:40:26 by bvarea-k          #+#    #+#             */
/*   Updated: 2026/02/26 15:53:39 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	add_collectible_to_list(t_game *game, int x, int y, int instance)
{
	t_collectible	*new_col;
	t_collectible	*current;

	new_col = malloc(sizeof(t_collectible));
	if (!new_col)
		return ;
	new_col->x = x;
	new_col->y = y;
	new_col->instance = instance;
	new_col->next = NULL;
	if (!game->collectibles_list)
		game->collectibles_list = new_col;
	else
	{
		current = game->collectibles_list;
		while (current->next)
			current = current->next;
		current->next = new_col;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->collectibles_list = NULL;
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
	game->player_instance = mlx_image_to_window(game->mlx, game->img_player,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

void	hide_collectible(t_game *game, int x, int y)
{
	t_collectible	*current;

	current = game->collectibles_list;
	while (current)
	{
		if (current->x == x && current->y == y)
		{
			game->img_collect->instances[current->instance].enabled = false;
			return ;
		}
		current = current->next;
	}
}

void	render_tile(t_game *game, int x, int y)
{
	int	px;
	int	py;
	int	instance;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	mlx_image_to_window(game->mlx, game->img_background, px, py);
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->img_wall, px, py);
	else if (game->map[y][x] == 'C')
	{
		instance = mlx_image_to_window(game->mlx, game->img_collect, px, py);
		add_collectible_to_list(game, x, y, instance);
	}
	else if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->img_exit, px, py);
}
