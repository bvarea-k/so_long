/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:54:44 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/07 11:51:18 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	load_image(mlx_t *mlx, mlx_image_t **img, const char *path)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png(path);
	if (!tex)
		return (0);
	*img = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	if (!(*img))
		return (0);
	return (1);
}

int	load_images(t_game *game)
{
	if (!load_image(game->mlx, &game->img_player, "img/player.png"))
		return (0);
	if (!load_image(game->mlx, &game->img_background, "img/background.png"))
		return (0);
	if (!load_image(game->mlx, &game->img_wall, "img/wall.png"))
		return (0);
	if (!load_image(game->mlx, &game->img_collect, "img/collect.png"))
		return (0);
	if (!load_image(game->mlx, &game->img_exit, "img/exit.png"))
		return (0);
	return (1);
}
