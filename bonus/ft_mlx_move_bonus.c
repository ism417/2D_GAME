/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:29:25 by eismail           #+#    #+#             */
/*   Updated: 2024/05/09 11:04:42 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_up(t_data *mlx_data, size_t *count)
{
	int	x;
	int	y;

	x = mlx_data->x;
	y = mlx_data->y;
	if (mlx_data->map[x - 1][y] == 'E' && mlx_data->c == *count)
		game_over(mlx_data, *count);
	else if (x > 0 && (mlx_data->map[x - 1][y] != 'E' 
		&& mlx_data->map[x - 1][y] != '1'))
	{
		if (mlx_data->map[(x) - 1][(y)] == 'C')
			(*count)++;
		if (mlx_data->map[x - 1][y] == 'T')
			game_over(mlx_data, 0);
		ft_img(mlx_data, 'P', (x * 65) - 65, y * 65);
		ft_img(mlx_data, '0', x * 65, y * 65);
		mlx_data->map[(x)][(y)] = '0';
		mlx_data->map[(x) - 1][(y)] = 'P';
		mlx_data->x -= 1;
		mlx_data->mv++;
	}
	else
		return ;
}

void	ft_down(t_data *mlx_data, size_t *count)
{
	int	x;
	int	y;

	x = mlx_data->x;
	y = mlx_data->y;
	if ((mlx_data->map[(x) + 1][(y)] == 'E') && (mlx_data->c == *count))
		game_over(mlx_data, *count);
	else if (x > 0 && (mlx_data->map[x + 1][y] != 'E' 
		&& mlx_data->map[x + 1][y] != '1'))
	{
		if (mlx_data->map[(x) + 1][(y)] == 'C')
			(*count)++;
		if (mlx_data->map[(x) + 1][(y)] == 'T')
			game_over(mlx_data, 0);
		ft_img(mlx_data, 'P', (x * 65) + 65, y * 65);
		ft_img(mlx_data, '0', x * 65, y * 65);
		mlx_data->map[(x)][(y)] = '0';
		mlx_data->map[(x) + 1][(y)] = 'P';
		mlx_data->x += 1;
		mlx_data->mv++;
	}
	else
		return ;
}

void	ft_right(t_data *mlx_data, size_t *count)
{
	int	x;
	int	y;

	x = mlx_data->x;
	y = mlx_data->y;
	if ((mlx_data->map[(x)][(y) + 1] == 'E') && (mlx_data->c == *count))
		game_over(mlx_data, *count);
	else if (x > 0 && (mlx_data->map[x][y + 1] != 'E' 
		&& mlx_data->map[x][y + 1] != '1'))
	{
		if (mlx_data->map[(x)][(y) + 1] == 'C')
			(*count)++;
		if (mlx_data->map[(x)][(y) + 1] == 'T')
			game_over(mlx_data, 0);
		sprite_right(mlx_data, x * 65, (y * 65) + 65);
		ft_img(mlx_data, '0', x * 65, y * 65);
		mlx_data->map[(x)][(y)] = '0';
		mlx_data->map[(x)][(y) + 1] = 'P';
		mlx_data->y += 1;
		mlx_data->mv++;
	}
	else
		return ;
}

void	ft_left(t_data *mlx_data, size_t *count)
{
	int	x;
	int	y;

	x = mlx_data->x;
	y = mlx_data->y;
	if ((mlx_data->map[(x)][(y) - 1] == 'E') && (mlx_data->c == *count))
		game_over(mlx_data, *count);
	else if (x > 0 && (mlx_data->map[x][y - 1] != '1' 
		&& mlx_data->map[x][y - 1] != 'E'))
	{
		if (mlx_data->map[(x)][(y) - 1] == 'C')
			(*count)++;
		if (mlx_data->map[(x)][(y) - 1] == 'T')
			game_over(mlx_data, 0);
		sprite_left(mlx_data, x * 65, (y * 65) - 65);
		ft_img(mlx_data, '0', x * 65, y * 65);
		mlx_data->map[(x)][(y)] = '0';
		mlx_data->map[(x)][(y) - 1] = 'P';
		mlx_data->y -= 1;
		mlx_data->mv++;
	}
	else
		return ;
}

int	move(int key, t_data *mlx_data)
{
	if (key == 53)
		cross(mlx_data);
	if (key == 126)
		ft_up(mlx_data, &(mlx_data->count));
	if (key == 125)
		ft_down(mlx_data, &(mlx_data->count));
	if (key == 124)
		ft_right(mlx_data, &(mlx_data->count));
	if (key == 123)
		ft_left(mlx_data, &(mlx_data->count));
	ft_bord(mlx_data);
	return (0);
}
