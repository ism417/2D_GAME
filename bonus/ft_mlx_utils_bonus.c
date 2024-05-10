/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:27:21 by eismail           #+#    #+#             */
/*   Updated: 2024/05/09 11:03:34 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_img(t_data *mlx_data, char c, int x, int y)
{
	int		w;
	int		h;
	char	*img_path;

	if (c == 'P')
		img_path = ft_strdup("./textures/P.xpm");
	else if (c == '1')
		img_path = ft_strdup("./textures/1.xpm");
	else if (c == 'E')
		img_path = ft_strdup("./textures/E.xpm");
	else if (c == 'C')
		img_path = ft_strdup("./textures/C.xpm");
	else
		img_path = ft_strdup("./textures/0.xpm");
	mlx_data->img = mlx_xpm_file_to_image(mlx_data->cnx, img_path, &w, &h);
	if (!mlx_data->img)
	{
		map_error(NULL, "Textures error\n");
		cross(mlx_data);
	}
	mlx_put_image_to_window(mlx_data->cnx, mlx_data->wind, mlx_data->img, y, x);
	free(img_path);
}

int	mlx_set(char **map, t_data *mlx_data)
{
	int	w;
	int	h;

	w = ft_strlen(map[0]) * 65;
	h = ft_height(map) * 65;
	if (w > 2535 || h > 1365)
	{
		free (mlx_data);
		map_error(map, "ginemenasaurus map!");
	}
	mlx_data->map = map;
	mlx_data->cnx = mlx_init();
	if (!mlx_data->cnx)
	{
		free(mlx_data);
		return (0);
	}
	mlx_data->wind = mlx_new_window(mlx_data->cnx, w, h, "./so_long_bonus");
	if (!mlx_data->wind)
	{
		free(mlx_data->cnx);
		free(mlx_data);
		return (0);
	}
	return (1);
}

void	desplay_map(t_data *mlx_data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (mlx_data->map[i])
	{
		j = 0;
		y = 0;
		while (mlx_data->map[i][j])
		{
			ft_img(mlx_data, '0', x, y);
			ft_img(mlx_data, mlx_data->map[i][j], x, y);
			j++;
			y += 65;
		}
		i++;
		x += 65;
	}
}

void	game_over(t_data *mlx_data, size_t count)
{
	if (count != mlx_data->c)
		put_game_over();
	else
	{
		ft_putstr_fd(" ************************************************\n", 1);
		ft_putstr_fd(" *    __  __                                    *\n", 1);
		ft_putstr_fd(" *    \\ \\/ /___  __  __   _      ______  ____   *\n", 1);
		ft_putstr_fd(" *     \\  / __ \\/ / / /  | | /| / / __ \\/ __ \\  *\n", 1);
		ft_putstr_fd(" *     / / /_/ / /_/ /   | |/ |/ / /_/ / / / /  *\n", 1);
		ft_putstr_fd(" *    /_/\\____/\\__,_/    |__/|__/\\____/_/ /_/   *\n", 1);
		ft_putstr_fd(" ************************************************\n", 1);
	}
	free_map(mlx_data->map);
	mlx_destroy_window(mlx_data->cnx, mlx_data->wind);
	free(mlx_data->arry);
	free(mlx_data);
	exit(0);
}

void	ft_mlx(t_data *mlx_data, char **map)
{
	int	i;

	i = mlx_set(map, mlx_data);
	if (!i)
		map_error(map, "mlx problem");
	mlx_data->c = element_check(map);
	mlx_data->t = element_count(map, 'T');
	mlx_data->count = 0;
	mlx_data->mv = 0;
	desplay_map(mlx_data);
	mlx_hook(mlx_data->wind, 2, 0, move, mlx_data);
	mlx_hook(mlx_data->wind, 17, 0, cross, mlx_data);
	mlx_loop_hook(mlx_data->cnx, ft_animation, mlx_data);
	mlx_loop(mlx_data->cnx);
}
