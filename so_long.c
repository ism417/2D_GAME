/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:17:19 by eismail           #+#    #+#             */
/*   Updated: 2024/05/09 11:22:06 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_game_over(void)
{
	ft_putstr_fd("**********************************************************\n",
		1);
	ft_putstr_fd("*    _________    __  _________   ____ _    ____________ *\n",
		1);
	ft_putstr_fd("*   / ____/   |  /  |/  / ____/  / __ \\ |  / / ____/ __ \\*\n",
		1);
	ft_putstr_fd("*  / / __/ /| | / /|_/ / __/    / / / / | / / __/ / /_/ /*\n", 
		1);
	ft_putstr_fd("* / /_/ / ___ |/ /  / / /___   / /_/ /| |/ / /___/ _, _/ *\n", 
		1);
	ft_putstr_fd("* \\____/_/  |_/_/  /_/_____/   \\____/ |___/_____/_/ |_|  *\n",
		1);
	ft_putstr_fd("**********************************************************\n",
		1);
}

char	**ft_check(t_data *mlx_data, char *s)
{
	char	*str;
	char	**map;

	map_name(s);
	str = read_map(s);
	if (!str)
		map_error(NULL, "Empty map\n");
	map = ft_split(str, '\n');
	if (!*map)
	{
		free(str);
		map_error(NULL, "memory problem\n");
	}
	dim_check(map, str);
	border_check(map);
	player_position(map, &mlx_data->x, &mlx_data->y);
	path_check(str, mlx_data);
	free(str);
	return (map);
}

int	main(int ac, char **av)
{
	int		i;
	char	**map;
	t_data	*mlx_data;

	i = 0;
	if (ac < 2 || !av[1][0])
		exit(1);
	mlx_data = malloc(sizeof(t_data));
	if (!mlx_data)
		exit(1);
	mlx_data->x = 1;
	mlx_data->y = 1;
	map = ft_check(mlx_data, av[1]);
	ft_mlx(mlx_data, map);
}
