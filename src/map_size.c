/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:08:43 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/06 09:59:58 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_height(t_game *game)
{
	int	height;

	height = 0;
	if (!game || !game->map)
		return (0);
	while (game->map[height])
		height++;
	return (height);
}

int	get_map_width(t_game *game)
{
	if (!game || !game->map || !game->map[0])
		return (0);
	return (ft_strlen(game->map[0]));
}
