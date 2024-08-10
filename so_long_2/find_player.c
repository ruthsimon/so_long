/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:32:33 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 21:29:40 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	find_pos_player(char **map_array, t_lay *lay)
{
	int	x;
	int	y;
	int	found;

	x = 0;
	found = 0;
	while (map_array[x] != NULL)
	{
		y = 0;
		while (map_array[x][y] != '\0')
		{
			if (map_array[x][y] == 'P')
			{
				found = 1;
				lay->player_pos_x = x;
				lay->player_pos_y = y;
				break ;
			}
			y++;
		}
		if (found)
			break ;
		x++;
	}
}

void	render_steps(t_lay *lay)
{
	char	*steps;

	steps = ft_itoa(lay->number_of_steps);
	mlx_string_put(lay->mlx_info->mlx, lay->mlx_info->mlx_win,
		20, 20, 0x000000, "Number of Steps:");
	mlx_string_put(lay->mlx_info->mlx, lay->mlx_info->mlx_win,
		140, 20, 0x000000, steps);
	free(steps);
}

void	put_image(t_lay *lay, int indicator, int x, int y)
{
	if (indicator == 1)
		mlx_put_image_to_window(lay->mlx_info->mlx, lay->mlx_info->mlx_win,
			lay->mlx_info->img_wall, y * 32, x * 32);
	else if (indicator == 2)
		mlx_put_image_to_window(lay->mlx_info->mlx, lay->mlx_info->mlx_win,
			lay->mlx_info->img_player_right, y * 32, x * 32);
	else if (indicator == 3)
		mlx_put_image_to_window(lay->mlx_info->mlx, lay->mlx_info->mlx_win,
			lay->mlx_info->img_player_left, y * 32, x * 32);
	else if (indicator == 4)
		mlx_put_image_to_window(lay->mlx_info->mlx, lay->mlx_info->mlx_win,
			lay->mlx_info->img_enemy1, y * 32, x * 32);
	else if (indicator == 5)
		mlx_put_image_to_window(lay->mlx_info->mlx, lay->mlx_info->mlx_win,
			lay->mlx_info->img_coin, y * 32, x * 32);
	else if (indicator == 6)
		mlx_put_image_to_window(lay->mlx_info->mlx, lay->mlx_info->mlx_win,
			lay->mlx_info->img_exit, y * 32, x * 32);
}

void	render(t_lay *lay)
{
	int	x;
	int	y;

	x = -1;
	while (lay->map_array[++x] != NULL)
	{
		y = -1;
		while (lay->map_array[x][++y] != '\0')
		{
			if (lay->map_array[x][y] == '1')
				put_image(lay, 1, x, y);
			else if (lay->map_array[x][y] == 'P' && lay->face_flag == 1)
				put_image(lay, 2, x, y);
			else if (lay->map_array[x][y] == 'P' && lay->face_flag == 2)
				put_image(lay, 3, x, y);
			else if (lay->map_array[x][y] == 'G')
				put_image(lay, 4, x, y);
			else if (lay->map_array[x][y] == 'C')
				put_image(lay, 5, x, y);
			else if (lay->map_array[x][y] == 'E')
				put_image(lay, 6, x, y);
		}
	}
	render_steps(lay);
}
