/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:23:07 by eismail           #+#    #+#             */
/*   Updated: 2024/05/10 10:12:46 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

typedef struct t_data
{
	void	*cnx;
	void	*wind;
	char	**map;
	int		width;
	int		height;
	int		x;
	int		y;
	int		e;
	int		is_minimized;
	int		*arry;
	size_t	c;
	size_t	t;
	size_t	mv;
	size_t	count;
	int		key;
	void	*img;
}		t_data;

/************** check map ****************/
char	**ft_check(t_data *mlx_data, char *s);
void	map_error(char **s, char *str);
void	map_name(char *s);
void	dim_check(char **s, char *str);
void	border_check(char **s);
void	path_check(char *str, t_data *mlx_data);
/************* utils ****************/
void	flood_fill(char **map, int x, int y, t_data *mlx_data);
size_t	element_check(char **s);
size_t	element_count(char **s, char c);
char	*read_map(char *s);
void	position(char **s, char c, int *x, int *y);
void	free_map(char **s);
void	free_read(char **s, char **s2);
int		ft_height(char **s);
int		ft_wedth(char **s);
void	put_game_over(void);
/************* mlx utils ******************/
int		cross(t_data *mlx_data);
int		move(int key, t_data *mlx_data);
int		cross(t_data *mlx_data);
void	ft_img(t_data *mlx_data, char c, int x, int y);
int		mlx_set(char **map, t_data *mlx_data);
void	desplay_map(t_data *mlx_data);
void	game_over(t_data *mlx_data, size_t count);
void	ft_mlx(t_data *mlx_data, char **map);
/************* animation utils ******************/
void	sprite_right(t_data *mlx_data, int x, int y);
int		ft_animation(t_data *mlx_data);
void	sprite_left(t_data *mlx_data, int x, int y);
int		ft_enemy(t_data *mlx_data);
int		ft_player(t_data *mlx_data);
int		*count_enemy(char *str);
void	put_a(t_data *mlx_data, char *img_path, int x, int y);
void	ft_bord(t_data *mlx_data);
#endif