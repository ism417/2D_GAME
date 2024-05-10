/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:29:25 by eismail           #+#    #+#             */
/*   Updated: 2024/05/08 22:53:07 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_data *mlx_data, size_t *count)
{
	int	x;
	int	y;

	x = (mlx_data->x * 65);
	y = mlx_data->y * 65;
	if (mlx_data->map[(mlx_data->x) - 1][(mlx_data->y)] == 'E')
	{
		if (mlx_data->c == *count)
			game_over(mlx_data, *count);
	}
	else if (x > 0 && mlx_data->map[(mlx_data->x) - 1][(mlx_data->y)] != '1')
	{
		if (mlx_data->map[(mlx_data->x) - 1][(mlx_data->y)] == 'C')
			(*count)++;
		ft_img(mlx_data, '0', x - 65, y);
		ft_img(mlx_data, 'P', x - 65, y);
		ft_img(mlx_data, '0', x, y);
		mlx_data->map[(mlx_data->x)][(mlx_data->y)] = '0';
		mlx_data->map[(mlx_data->x) - 1][(mlx_data->y)] = 'P';
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

	x = (mlx_data->x * 65);
	y = mlx_data->y * 65;
	if (mlx_data->map[(mlx_data->x) + 1][(mlx_data->y)] == 'E')
	{
		if (mlx_data->c == *count)
			game_over(mlx_data, *count);
	}
	else if (x > 0 && mlx_data->map[(mlx_data->x) + 1][(mlx_data->y)] != '1')
	{
		if (mlx_data->map[(mlx_data->x) + 1][(mlx_data->y)] == 'C')
			(*count)++;
		ft_img(mlx_data, '0', x + 65, y);
		ft_img(mlx_data, 'P', x + 65, y);
		ft_img(mlx_data, '0', x, y);
		mlx_data->map[(mlx_data->x)][(mlx_data->y)] = '0';
		mlx_data->map[(mlx_data->x) + 1][(mlx_data->y)] = 'P';
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

	x = (mlx_data->x * 65);
	y = mlx_data->y * 65;
	if (mlx_data->map[(mlx_data->x)][(mlx_data->y) + 1] == 'E')
	{
		if (mlx_data->c == *count)
			game_over(mlx_data, *count);
	}
	else if (x > 0 && mlx_data->map[(mlx_data->x)][(mlx_data->y) + 1] != '1')
	{
		if (mlx_data->map[(mlx_data->x)][(mlx_data->y) + 1] == 'C')
			(*count)++;
		ft_img(mlx_data, '0', x, y + 65);
		ft_img(mlx_data, 'P', x, y + 65);
		ft_img(mlx_data, '0', x, y);
		mlx_data->map[(mlx_data->x)][(mlx_data->y)] = '0';
		mlx_data->map[(mlx_data->x)][(mlx_data->y) + 1] = 'P';
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

	x = (mlx_data->x * 65);
	y = mlx_data->y * 65;
	if (mlx_data->map[(mlx_data->x)][(mlx_data->y) - 1] == 'E')
	{
		if (mlx_data->c == *count)
			game_over(mlx_data, *count);
	}
	else if (x > 0 && mlx_data->map[(mlx_data->x)][(mlx_data->y) - 1] != '1')
	{
		if (mlx_data->map[(mlx_data->x)][(mlx_data->y) - 1] == 'C')
			(*count)++;
		ft_img(mlx_data, '0', x, y - 65);
		ft_img(mlx_data, 'P', x, y - 65);
		ft_img(mlx_data, '0', x, y);
		mlx_data->map[(mlx_data->x)][(mlx_data->y)] = '0';
		mlx_data->map[(mlx_data->x)][(mlx_data->y) - 1] = 'P';
		mlx_data->y -= 1;
		mlx_data->mv++;
	}
	else
		return ;
}

int	move(int key, t_data *mlx_data)
{
	size_t	hold;

	hold = mlx_data->mv;
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
	if (hold != mlx_data->mv)
	{
		ft_putstr_fd("movement count : ", 1);
		ft_putnbr_fd(mlx_data->mv, 1);
		write(1, "\n", 1);
	}
	return (0);
}
