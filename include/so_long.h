/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgo <bgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:42:21 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/08/07 17:07:12 by bgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# include "MLX42/MLX42.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img_player;
	mlx_image_t	*img_background;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_collect;
	char		**map;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			moves;
	int			width;
	int			height;
}	t_game;

void	error_exit(const char *msg);
void	map_error(t_game *game, const char *s);
char	**read_map_file(const char *file, t_game *game);
int		load_image(mlx_t *mlx, mlx_image_t **img, const char *path);
int		load_images(t_game *game);
void	ft_init_game(t_game *game);
char	**copy_map(t_game *game);
void	free_map(char **map);
void	flood_fill(char **map, int y, int x);
int		map_is_solvable(char **map);
void	check_solvability(t_game *game);
void	check_extension(char *str);
void	check(t_game *game);
void	check_col_play_exit(t_game *game);
void	check_valid_char(t_game *game);
int		get_map_height(t_game *game);
int		get_map_width(t_game *game);
void	check_lines_columns(t_game *game);
char	*ft_strjoin_so_long(char *s1, char *s2);
void	draw_map(t_game *game);
void	handle_input(mlx_key_data_t keydata, void *param);
void	close_game(t_game *game);
void	move_player(t_game *game, int dx, int dy);
void	render_tile(t_game *game, int x, int y);
void	count_col_play_exit(t_game *game, int *player, int *col, int *exit);
void	validate_col_play_exit(t_game *game, int player, int col, int exit);
void	locate_player(t_game *game);
void	cleanup_gnl(void);
int		process_move(t_game *game, int new_x, int new_y);
void	extra_main(t_game *game);

#endif
