/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:06:44 by flvoicu           #+#    #+#             */
/*   Updated: 2024/10/29 19:16:19 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*poo;
	void	*pee;
	void	*fly;
	void	*floor;
	void	*toilet_c;
	void	*toilet_o;
	int		coins;
	int		sal[2];
	char	**map;
	int		dim[2];
	int		moves;
}			t_game;

void	free_map(char **map);
void	ft_s(char *s);
void	ft_u(unsigned int i);
void	write_moves(int i);
void	message_exit(char *s, char **map, t_game *game, int error);
int		get_width(int fd, int bytes, char *buffer, int i);
int		get_height(int fd, int bytes, char	*buffer);
int		*get_map_dimensions(char *dir, int *data);
void	populate_map(char **map, int fd, int k, int j);
char	**get_map(char *dir, int *data);
void	check_coins_exit(t_game *game);
void	check_data(char **map);
void	check_limit(char **map, int *dim);
void	check_path(char	**map, int i, int j);
void	get_player(char **map);
void	check_map(char **map, int *dim);
void	check_asset(t_game *game, int i, int j);
int		add_assets(t_game *game);
void	get_coin(int key, t_game *game, int i, int j);
void	key_move(int key, t_game *game, int i, int j);
int		close_button(t_game *game);
int		get_key(int key, t_game *game);
void	initialize_game(t_game *game);

#endif
