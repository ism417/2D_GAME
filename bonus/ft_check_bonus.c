/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:18:18 by eismail           #+#    #+#             */
/*   Updated: 2024/05/07 10:16:58 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_error(char **s, char *str)
{
	free_map(s);
	ft_putstr_fd("ERROR\n", 1);
	ft_putstr_fd(str, 1);
	exit(1);
}

void	map_name(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.')
		{
			if (ft_strncmp(&s[i], ".ber", 5) != 0)
				map_error(NULL, "map name must be .ber\n");
		}
		i++;
	}
}

void	dim_check(char **s, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str) - 1;
	if (str[0] == '\n' || str[len] != '1')
	{
		free(str);
		map_error(s, "the chape of the map is not right\n");
	}
	while (s[i])
	{
		if (s[i + 1])
		{
			if (ft_strlen(s[i]) != ft_strlen(s[i + 1]))
			{
				free(str);
				map_error(s, "the chape of the map is not right\n");
			}
		}
		i++;
	}
}

void	border_check(char **s)
{
	int	i;
	int	e;

	i = 0;
	e = ft_strlen(s[i]) - 1;
	while (s[i])
	{
		if ((s[i][0] != '1') || (s[i][e] != '1'))
			map_error(s, "the border must contain ony walls '1'\n");
		i++;
	}
	e = i - 1;
	i = 0;
	while (s[0][i] && s[e][i])
	{
		if (s[0][i] != '1' || s[e][i] != '1')
			map_error(s, "the border must contain ony walls '1'\n");
		i++;
	}
}

void	path_check(char *str, t_data *mlx_data)
{
	size_t	count;
	t_data	*mlx_temp;
	char	**map;

	map = ft_split(str, '\n');
	mlx_temp = malloc(sizeof(t_data));
	mlx_temp->c = 0;
	mlx_temp->e = 0;
	if (!*map)
	{
		free(mlx_data);
		map_error(map, "memory problem\n");
	}
	count = element_check(map);
	flood_fill(map, mlx_data->x, mlx_data->y, mlx_temp);
	if (mlx_temp->c != count || mlx_temp->e != 1)
		map_error(map, "there is no way to win\n");
	free_map(map);
	free(mlx_temp);
}
