/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:29:49 by flvoicu           #+#    #+#             */
/*   Updated: 2024/09/16 19:13:37 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	j;

	j = 0;
	if (map)
	{
		while (map[j])
		{
			free (map[j]);
			j++;
		}
		free(map[j]);
		free (map);
	}
}

void	ft_s(char *s)
{
	char	*p;

	p = s;
	if (!p)
		return ;
	while (*p)
	{
		write(1, p, 1);
		p++;
	}
}

void	write_moves(int i)
{
	ft_u(i);
	write(1, "\n", 1);
}

void	ft_u(unsigned int i)
{
	if (i == 0)
	{
		write(1, "0", 1);
	}
	if (i != 0)
	{
		if (i / 10 != 0)
			ft_u(i / 10);
		write(1, &(char){i % 10 + '0'}, 1);
	}
}

void	message_exit(char *s, char **map, t_game *game, int error)
{
	ft_s(s);
	if (game)
	{
		free_map(game->map);
		if (game->toilet_c)
			mlx_destroy_image(game->mlx, game->toilet_c);
		if (game->toilet_o)
			mlx_destroy_image(game->mlx, game->toilet_o);
		if (game->fly)
			mlx_destroy_image(game->mlx, game->fly);
		if (game->floor)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->poo)
			mlx_destroy_image(game->mlx, game->poo);
		if (game->pee)
			mlx_destroy_image(game->mlx, game->pee);
		if (game->mlx_win)
			mlx_destroy_window(game->mlx, game->mlx_win);
		// if (game->mlx)
		// 	mlx_destroy_display(game->mlx); //doesnt work on macos
		free(game->mlx);
	}
	free_map(map);
	exit (error);
}
