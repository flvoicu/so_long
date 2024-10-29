/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:09:00 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 16:51:57 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_asset(t_game *game, int i, int j)
{
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->pee, \
		(i * 64), (j * 64));
	if (game->map[j][i] == 'E' || (i == game->sal[0] && j == game->sal[1]))
	{
		if (game->coins)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->toilet_c, \
			(game->sal[0] * 64), (game->sal[1] * 64));
		else
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->toilet_o, \
			(game->sal[0] * 64), (game->sal[1] * 64));
	}
	if (game->map[j][i] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->poo, \
		(i * 64), (j * 64));
	if (game->map[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->fly, \
		(i * 64), (j * 64));
	if (game->map[j][i] == 'P' && !game->coins &&
	i == game->sal[0] && j == game->sal[1])
		message_exit("GGS\n", 0, game, 0);
}

int	add_assets(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, \
				(i * 64), (j * 64));
			check_asset(game, i, j);
			i++;
		}
		j++;
	}
	return (0);
}
