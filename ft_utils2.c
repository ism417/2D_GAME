/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:32:04 by eismail           #+#    #+#             */
/*   Updated: 2024/05/05 21:58:12 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_wedth(char **s)
{
	return (ft_strlen(s[0]));
}

int	cross(t_data *mlx_data)
{
	game_over(mlx_data, 0);
	free_map(mlx_data->map);
	mlx_destroy_window(mlx_data->cnx, mlx_data->wind);
	free(mlx_data);
	exit(0);
}
