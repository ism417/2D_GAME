/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:32:04 by eismail           #+#    #+#             */
/*   Updated: 2024/05/09 11:04:51 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return ;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
}

void	free_read(char **s, char **s2)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
}

int	ft_height(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bord(t_data *mlx_data)
{
	char	*mv;
	char	*mvn;
	char	*score;
	char	*scoren;

	score = ft_strdup("score");
	mv = ft_strdup("moves");
	mvn = ft_itoa(mlx_data->mv);
	scoren = ft_itoa(mlx_data->count);
	ft_img(mlx_data, '0', 0, 0);
	mlx_string_put(mlx_data->cnx, mlx_data->wind, 10, 15, 0x000000, mv);
	mlx_string_put(mlx_data->cnx, mlx_data->wind, 10, 30, 0x000000, mvn);
	mlx_string_put(mlx_data->cnx, mlx_data->wind, 10, 45, 0x000000, score);
	mlx_string_put(mlx_data->cnx, mlx_data->wind, 10, 60, 0x000000, scoren);
	free(mv);
	free(score);
	free(mvn);
	free(scoren);
}

int	cross(t_data *mlx_data)
{
	game_over(mlx_data, 0);
	free_map(mlx_data->map);
	mlx_destroy_window(mlx_data->cnx, mlx_data->wind);
	free(mlx_data->arry);
	free(mlx_data);
	exit(0);
}
