/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:48:00 by bvarea-k          #+#    #+#             */
/*   Updated: 2026/02/26 15:48:49 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_game(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_map(game->map);
	exit(EXIT_SUCCESS);
}