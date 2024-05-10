/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:20:10 by eismail           #+#    #+#             */
/*   Updated: 2024/05/09 11:37:13 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	element_check(char **s)
{
	if (element_count(s, 'P') > 1 || element_count(s, 'P') == 0)
		map_error(s, "the map must contain ony one player 'P'\n");
	if (element_count(s, 'C') < 1)
		map_error(s, "the map must contain at least one coin 'C'\n");
	if (element_count(s, 'E') > 1 || element_count(s, 'E') == 0)
		map_error(s, "the map must contain ony exit 'E'\n");
	return (element_count(s, 'C'));
}

void	flood_fill(char **map, int x, int y, t_data *mlx_data)
{
	if (map[x][y] == '1')
		return ;
	if (map[x][y] == 'E')
	{
		(mlx_data->e)++;
		map[x][y] = '1';
		return ;
	}
	if (map[x][y] == 'C')
		(mlx_data->c)++;
	map[x][y] = '1';
	flood_fill(map, x, y + 1, mlx_data);
	flood_fill(map, x + 1, y, mlx_data);
	flood_fill(map, x - 1, y, mlx_data);
	flood_fill(map, x, y - 1, mlx_data);
}

size_t	element_count(char **s, char c)
{
	int		i;
	int		j;
	size_t	count;

	i = 1;
	j = 1;
	count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != 'P' && s[i][j] != 'C' && s[i][j] != 'E' 
				&& s[i][j] != '1' && s[i][j] != '0')
				map_error(s, "Only 'P' 'E' 'C' '1' '0'\n");
			if (s[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	*read_map(char *s)
{
	char	*map;
	char	*buffer;
	int		n;
	int		fd;

	n = 42;
	map = NULL;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		map_error(NULL, "File not found\n");
	buffer = malloc(sizeof(char) * 2);
	while (n > 0)
	{
		n = read(fd, buffer, 2);
		if (n <= 0)
			break ;
		buffer[n] = '\0';
		map = ft_strjoin(map, buffer);
		if (!map)
			return (free_read(&buffer, &map), NULL);
	}
	free(buffer);
	return (map);
}

void	player_position(char **s, int *x, int *y)
{
	while (s[*x])
	{
		*y = 1;
		while (s[*x][*y])
		{
			if (s[*x][*y] == 'P')
				return ;
			(*y)++;
		}
		(*x)++;
	}
}
