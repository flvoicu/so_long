/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:05:33 by flvoicu           #+#    #+#             */
/*   Updated: 2024/06/17 18:25:05 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_game *game)
{
	int	s[1];

	s[0] = 64;
	game->mlx = mlx_init();
	if (!game->mlx)
		message_exit("No se puede inicializar la minilib", 0, 0, 1);
	game->mlx_win = mlx_new_window(game->mlx, \
	game->dim[1] * 64, game->dim[0] * 64, "POPO");
	if (!game->mlx_win)
		message_exit("No se ha podido crear la ventana", 0, game, 1);
	game->pee = mlx_xpm_file_to_image(game->mlx, "./assets/pee.xpm", \
	s, s);
	game->poo = mlx_xpm_file_to_image(game->mlx, "./assets/poo.xpm", \
	s, s);
	game->floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm", \
	s, s);
	game->fly = mlx_xpm_file_to_image(game->mlx, "./assets/fly.xpm", \
	s, s);
	game->toilet_o = mlx_xpm_file_to_image(game->mlx, "./assets/toilet-o.xpm", \
	s, s);
	game->toilet_c = mlx_xpm_file_to_image(game->mlx, "./assets/toilet-c.xpm", \
	s, s);
	game->moves = 0;
}

int	check_ber(char *dir)
{
	int		i;
	char	*ber;

	i = 0;
	while (dir[i] != '\0')
		i++;
	ber = ".ber";
	i -= 4;
	while (dir[i] != '\0')
	{
		if (dir[i] != *ber)
			return (0);
		i++;
		ber++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_game	game;
	char	*dir;

	if (ac != 2)
		return (0);
	dir = av[1];
	if (!check_ber(dir))
		message_exit("not a .ber file\n", 0, 0, 1);
	get_map_dimensions(dir, game.dim);
	check_map(get_map(dir, game.dim), game.dim);
	initialize_game(&game);
	game.map = get_map(dir, game.dim);
	check_coins_exit(&game);
	mlx_key_hook(game.mlx_win, get_key, &game);
	mlx_hook(game.mlx_win, 17, 0, close_button, &game);
	mlx_loop_hook(game.mlx, add_assets, &game);
	mlx_loop(game.mlx);
	return (0);
}
