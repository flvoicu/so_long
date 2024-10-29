/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:02:54 by flvoicu           #+#    #+#             */
/*   Updated: 2024/06/17 18:24:31 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_width(int fd, int bytes, char *buffer, int i)
{
	int	count;
	int	first;

	first = 0;
	count = 0;
	while (bytes)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				if (!first)
					first = i;
				if (count != first)
					message_exit("ErrorIO\n", 0, 0, 0);
				count = -1;
			}
			count++;
			i++;
		}
		bytes = read(fd, buffer, 99);
		buffer[bytes] = '\0';
	}
	return (first);
}

int	get_height(int fd, int bytes, char	*buffer)
{
	int	i;
	int	count;

	count = 0;
	while (bytes)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
		bytes = read(fd, buffer, 99);
		buffer[bytes] = '\0';
	}
	return (count);
}

int	*get_map_dimensions(char *dir, int *data)
{
	char	buffer[100];
	int		bytes;
	int		fd;

	fd = open (dir, O_RDONLY);
	bytes = read(fd, buffer, 99);
	if (fd == -1 || bytes == -1)
		message_exit("Error\n", 0, 0, 0);
	buffer[bytes] = '\0';
	data[0] = get_height(fd, bytes, buffer);
	close (fd);
	fd = open (dir, O_RDONLY);
	bytes = read(fd, buffer, 99);
	if (fd == -1 || bytes == -1)
		message_exit("Error\n", 0, 0, 0);
	buffer[bytes] = '\0';
	data[1] = get_width(fd, bytes, buffer, 0);
	close (fd);
	return (data);
}

void	populate_map(char **map, int fd, int k, int j)
{
	int		i;
	int		bytes;
	char	buffer[100];

	bytes = read(fd, buffer, 99);
	buffer[bytes] = '\0';
	while (bytes)
	{
		i = 0;
		while (buffer[i] && map[j])
		{
			map[j][k] = buffer[i];
			if (buffer[i] == '\n')
			{
				map[j][k] = '\0';
				j++;
				k = -1;
			}
			i++;
			k++;
		}
		bytes = read(fd, buffer, 99);
		buffer[bytes] = '\0';
	}
}

char	**get_map(char *dir, int *data)
{
	int		fd;
	char	**map;
	int		i;

	fd = open (dir, O_RDONLY);
	map = malloc ((data[0] + 1) * sizeof(char *));
	map[data[0]] = 0;
	i = 0;
	while (i < data[0])
	{
		map[i] = malloc ((data[1] + 1) * sizeof(char));
		i++;
	}
	populate_map(map, fd, 0, 0);
	close (fd);
	return (map);
}
