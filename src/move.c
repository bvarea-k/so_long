/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:09:53 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/07 11:46:50 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	locate_player(t_game *game)
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
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_game(game);
	else if (keydata.key == MLX_KEY_W)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_S)
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_A)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_D)
		move_player(game, 1, 0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!process_move(game, new_x, new_y))
		return ;
	ft_printf("Moves: %d\n", game->moves);
	draw_map(game);
}

int	process_move(t_game *game, int new_x, int new_y)
{
	char	tile;

	tile = game->map[new_y][new_x];
	if (tile == WALL)
		return (0);
	if (tile == COLLECTIBLE)
	{
		game->collectibles--;
		game->map[new_y][new_x] = FLOOR;
	}
	if (tile == EXIT && game->collectibles == 0)
	{
		ft_printf("You have won in %d moves!\n", ++game->moves);
		close_game(game);
	}
	if (game->map[game->player_y][game->player_x] != EXIT)
		game->map[game->player_y][game->player_x] = FLOOR;
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	return (1);
}

void	close_game(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_map(game->map);
	exit(EXIT_SUCCESS);
}
