/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:09:49 by flvoicu           #+#    #+#             */
/*   Updated: 2024/08/26 20:53:12 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_coins_exit(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	game->coins = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'C')
				game->coins++;
			if (game->map[j][i] == 'E')
			{
				game->sal[0] = i;
				game->sal[1] = j;
			}
			i++;
		}
		j++;
	}
}

void	get_coin(int key, t_game *game, int i, int j)
{
	if ((key == 65362 || key == 119) && game->map[j - 1][i] == 'C')
		game->coins--;
	if ((key == 65361 || key == 97) && game->map[j][i - 1] == 'C')
		game->coins--;
	if ((key == 65364 || key == 115) && game->map[j + 1][i] == 'C')
		game->coins--;
	if ((key == 65363 || key == 100) && game->map[j][i + 1] == 'C')
		game->coins--;
	key_move(key, game, i, j);
}

void	key_move(int key, t_game *game, int i, int j)
{
	if ((key == 65362 || key == 119) && game->map[j - 1][i] != '1')
	{
		game->map[j][i] = '0';
		game->map[j - 1][i] = 'P';
		game->moves++;
	}
	if ((key == 65361 || key == 97) && game->map[j][i - 1] != '1')
	{
		game->map[j][i] = '0';
		game->map[j][i - 1] = 'P';
		game->moves++;
	}
	if ((key == 65364 || key == 115) && game->map[j + 1][i] != '1')
	{
		game->map[j][i] = '0';
		game->map[j + 1][i] = 'P';
		game->moves++;
	}
	if ((key == 65363 || key == 100) && game->map[j][i + 1] != '1')
	{
		game->map[j][i] = '0';
		game->map[j][i + 1] = 'P';
		game->moves++;
	}
}

int	close_button(t_game *game)
{
	message_exit("Exiteando\n", 0, game, 0);
	return (0);
}

int	get_key(int key, t_game *game)
{
	int	i;
	int	j;
	int	tmp;

	if (key == 65307)
		message_exit("Escapando\n", 0, game, 0);
	j = 0;
	tmp = game->moves;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] && game->map[j][i] != 'P')
			i++;
		if (game->map[j][i] == 'P')
			break ;
		j++;
	}
	get_coin(key, game, i, j);
	if (tmp != game->moves)
		write_moves(game->moves);
	return (0);
}
