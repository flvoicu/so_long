/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:01:09 by flvoicu           #+#    #+#             */
/*   Updated: 2024/08/26 20:52:55 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_data(char **map)
{
	int	i;
	int	j;
	int	data[2];

	j = 0;
	data[0] = 0;
	data[1] = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'E' || map[j][i] == 'P')
				data[0]++;
			else if (map[j][i] == 'C')
				data[1]++;
			else if (map[j][i] != '0' && map[j][i] != '1')
				message_exit("Error\n", map, 0, 0);
			i++;
		}
		j++;
	}
	if (data[0] != 2 || data[1] == 0)
		message_exit("Error\n", map, 0, 0);
}

void	check_limit(char **map, int *dim)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j][i] != '\0')
	{
		if (map[j][i] != '1')
			message_exit("Error\n", map, 0, 0);
		i++;
	}
	j++;
	while (j < dim[0] - 1)
	{
		if (map[j][0] != '1' || map[j][dim[1] - 1] != '1')
			message_exit("Error\n", map, 0, 0);
		j++;
	}
	i = 0;
	while (map[j][i] != '\0')
	{
		if (map[j][i] != '1')
			message_exit("Error\n", map, 0, 0);
		i++;
	}
}

void	check_path(char	**map, int i, int j)
{
	if (map[i][j] != '1')
		map[i][j] = '1';
	if (map[i][j - 1] != '1')
		check_path(map, i, j - 1);
	if (map[i][j + 1] != '1')
		check_path(map, i, j + 1);
	if (map[i - 1][j] != '1')
		check_path(map, i - 1, j);
	if (map[i + 1][j] != '1')
		check_path(map, i + 1, j);
}

void	get_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				check_path(map, i, j);
			j++;
		}
		i++;
	}
}

void	check_map(char **map, int *dim)
{
	int		i;
	int		j;

	j = 0;
	check_data(map);
	check_limit(map, dim);
	get_player(map);
	while (map[j])
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'C' || map[j][i] == 'E')
				message_exit("Error\n", map, 0, 0);
			i++;
		}
		j++;
	}
	free_map(map);
}
