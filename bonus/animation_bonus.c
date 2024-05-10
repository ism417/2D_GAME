/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:42:06 by eismail           #+#    #+#             */
/*   Updated: 2024/05/07 10:31:26 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sprite_right(t_data *mlx_data, int x, int y)
{
	int		w;
	int		h;
	char	*img_path;
	int		i;

	i = 0;
	img_path = ft_strdup("./textures/P7.xpm");
	ft_img(mlx_data, '0', x, y);
	mlx_data->img = mlx_xpm_file_to_image(mlx_data->cnx, img_path, &w, &h);
	if (!mlx_data->img)
	{
		map_error(NULL, "Textures error\n");
		free_map(mlx_data->map);
		mlx_destroy_window(mlx_data->cnx, mlx_data->wind);
		free(mlx_data);
		exit(0);
	}
	mlx_put_image_to_window(mlx_data->cnx, mlx_data->wind, mlx_data->img, y, x);
	i++;
	free(img_path);
	mlx_data->key = 1;
}

void	sprite_left(t_data *mlx_data, int x, int y)
{
	int		w;
	int		h;
	char	*img_path;
	int		i;

	i = 0;
	img_path = ft_strdup("./textures/P7left.xpm");
	ft_img(mlx_data, '0', x, y);
	mlx_data->img = mlx_xpm_file_to_image(mlx_data->cnx, img_path, &w, &h);
	if (!mlx_data->img)
	{
		map_error(NULL, "Textures error\n");
		free_map(mlx_data->map);
		mlx_destroy_window(mlx_data->cnx, mlx_data->wind);
		free(mlx_data);
		exit(0);
	}
	mlx_put_image_to_window(mlx_data->cnx, mlx_data->wind, mlx_data->img, y, x);
	i++;
	free(img_path);
	mlx_data->key = 2;
}

int	*count_enemy(char *str)
{
	char	**map;
	int		*arry;
	int		t;
	int		i;

	i = 0;
	map = ft_split(str, '\n');
	t = element_count(map, 'T');
	arry = malloc((t * 2) * sizeof(int));
	while (t > 0)
	{
		arry[i] = 0;
		arry[i + 1] = 0;
		position(map, 'T', &arry[i], &arry[i + 1]);
		map[arry[i]][arry[i + 1]] = '0';
		t--;
		i += 2;
	}
	free_map(map);
	return (arry);
}

int	ft_player(t_data *mlx_data)
{
	char		**img_path;
	static int	i;

	if (mlx_data->key == 2)
		img_path = ft_split("./textures/Pa1.xpm ./textures/Pa2.xpm", ' ');
	else
		img_path = ft_split("./textures/Pr1.xpm ./textures/Pr2.xpm", ' ');
	i++;
	if (i == 2000)
		put_a(mlx_data, img_path[0], (mlx_data->x), (mlx_data->y));
	else if (i == 4000)
	{
		put_a(mlx_data, img_path[1], (mlx_data->x), (mlx_data->y));
		i = 0;
	}
	free_map(img_path);
	return (0);
}

int	ft_enemy(t_data *mlx_data)
{
	char		**p;
	static int	i;
	size_t		j;

	j = 0;
	p = ft_split("./textures/T1.xpm\t./textures/T2.xpm\
	./textures/T3.xpm\t./textures/T3.xpm", '\t');
	i++;
	while (j < (mlx_data->t) * 2)
	{
		if (i == 2000)
			put_a(mlx_data, p[0], mlx_data->arry[j], mlx_data->arry[j + 1]);
		else if (i == 4000)
			put_a(mlx_data, p[1], mlx_data->arry[j], mlx_data->arry[j + 1]);
		else if (i == 6000)
			put_a(mlx_data, p[2], mlx_data->arry[j], mlx_data->arry[j + 1]);
		else if (i == 8000)
		{
			put_a(mlx_data, p[3], mlx_data->arry[j], mlx_data->arry[j + 1]);
			i = 0;
		}
		j += 2;
	}
	free_map(p);
	return (0);
}
