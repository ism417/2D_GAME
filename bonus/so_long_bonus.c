/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:17:19 by eismail           #+#    #+#             */
/*   Updated: 2024/05/09 11:23:36 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	put_a(t_data *mlx_data, char *img_path, int x, int y)
{
	int	w;
	int	h;

	mlx_destroy_image(mlx_data->cnx, mlx_data->img);
	ft_img(mlx_data, '0', x * 65, y * 65);
	mlx_data->img = mlx_xpm_file_to_image(mlx_data->cnx, img_path, &w, &h);
	if (!mlx_data->img)
	{
		map_error(NULL, "Textures error\n");
		cross(mlx_data);
	}
	mlx_put_image_to_window(mlx_data->cnx, mlx_data->wind, mlx_data->img,
		y * 65, x * 65);
}

int	ft_animation(t_data *mlx_data)
{
	ft_enemy(mlx_data);
	ft_player(mlx_data);
	return (0);
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
	position(map, 'P', &mlx_data->x, &mlx_data->y);
	path_check(str, mlx_data);
	mlx_data->arry = count_enemy(str);
	free (str);
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
	mlx_data->x = 1;
	mlx_data->y = 1;
	map = ft_check(mlx_data, av[1]);
	ft_mlx(mlx_data, map);
}
