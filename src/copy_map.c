/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:57:04 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/07/30 10:57:08 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**copy_map(t_game *game)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		map_error(game, "Error while copying the map");
	y = 0;
	while (y < game->height)
	{
		copy[y] = ft_strdup(game->map[y]);
		if (!copy[y])
			map_error(game, "Error while copying map line");
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

void	flood_fill(char **map, int y, int x)
{
	char	c;

	if (y < 0 || x < 0 || !map[y] || map[y][x] == '\0')
		return ;
	c = map[y][x];
	if (c == '1' || c == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}

int	map_is_solvable(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	check_solvability(t_game *game)
{
	char	**copy;
	int		y;
	int		x;

	copy = copy_map(game);
	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'P')
			{
				flood_fill(copy, y, x);
				if (!map_is_solvable(copy))
					map_error(game, "Cannot reach all elements.");
				free_map(copy);
				return ;
			}
			x++;
		}
		y++;
	}
	free_map(copy);
}
