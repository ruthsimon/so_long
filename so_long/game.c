/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:44 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 17:43:23 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	render(t_lay *lay, t_mlx_info *info)
{
	int	x;
	int	y;

	x = 0;
	while (lay->map_array[x] != NULL)
	{
		y = 0;
		while (lay->map_array[x][y] != '\0')
		{
			if (lay->map_array[x][y] == '1')
				mlx_put_image_to_window(info->mlx, info->mlx_win,
					info->img_wall, y * 32, x * 32);
			else if (lay->map_array[x][y] == 'P')
				mlx_put_image_to_window(info->mlx, info->mlx_win,
					info->img_player, y * 32, x * 32);
			else if (lay->map_array[x][y] == 'C')
				mlx_put_image_to_window(info->mlx, info->mlx_win,
					info->img_coin, y * 32, x * 32);
			else if (lay->map_array[x][y] == 'E')
				mlx_put_image_to_window(info->mlx, info->mlx_win,
					info->img_exit, y * 32, x * 32);
			y++;
		}
		x++;
	}
}

void	right_move(t_lay *lay2)
{
	if (lay2->map_array[lay2->player_pos_x][lay2->player_pos_y + 1] == '0'
		|| lay2->map_array[lay2->player_pos_x][lay2->player_pos_y + 1] == 'C'
		|| lay2->map_array[lay2->player_pos_x][lay2->player_pos_y + 1] == 'E')
	{
		if (lay2->map_array[lay2->player_pos_x][lay2->player_pos_y + 1] == 'C')
			lay2->n_collected++;
		else if (lay2->map_array[lay2->player_pos_x][lay2->player_pos_y + 1]
			== 'E' && lay2->n_collected == lay2->n_2bcollected)
		{
			mlx_destroy_window(lay2->mlx_info->mlx, lay2->mlx_info->mlx_win);
			exit(0);
		}
		if (lay2->map_array[lay2->player_pos_x][lay2->player_pos_y + 1] == '0'
		|| lay2->map_array[lay2->player_pos_x][lay2->player_pos_y + 1] == 'C')
		{
			lay2->map_array[lay2->player_pos_x][lay2->player_pos_y] = '0';
			lay2->map_array[lay2->player_pos_x][lay2->player_pos_y + 1] = 'P';
			lay2->player_pos_y += 1;
			lay2->number_of_steps++;
			ft_printf("Number of steps: %i \n", lay2->number_of_steps);
		}
	}
}

void	left_move(t_lay *lay2)
{
	if (lay2->map_array[lay2->player_pos_x][lay2->player_pos_y - 1] == '0'
	|| lay2->map_array[lay2->player_pos_x][lay2->player_pos_y - 1] == 'C'
	|| lay2->map_array[lay2->player_pos_x][lay2->player_pos_y - 1] == 'E' )
	{
		if (lay2->map_array[lay2->player_pos_x][lay2->player_pos_y - 1] == 'C')
			lay2->n_collected++;
		else if (lay2->map_array[lay2->player_pos_x][lay2->player_pos_y - 1]
		== 'E' && lay2->n_collected == lay2->n_2bcollected)
		{
			mlx_destroy_window(lay2->mlx_info->mlx, lay2->mlx_info->mlx_win);
			exit(0);
		}
		if (lay2->map_array[lay2->player_pos_x][lay2->player_pos_y - 1] == '0'
		|| lay2->map_array[lay2->player_pos_x][lay2->player_pos_y - 1] == 'C')
		{
			lay2->map_array[lay2->player_pos_x][lay2->player_pos_y] = '0';
			lay2->map_array[lay2->player_pos_x][lay2->player_pos_y - 1] = 'P';
			lay2->player_pos_y -= 1;
			lay2->number_of_steps++;
			ft_printf("Number of steps: %i \n", lay2->number_of_steps);
		}
	}
}

void	up_move(t_lay *lay2)
{
	if (lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] == '0'
	|| lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] == 'C'
	|| lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] == 'E' )
	{
		if (lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] == 'C' )
			lay2->n_collected++;
		else if (lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y]
		== 'E' && lay2->n_collected == lay2->n_2bcollected)
		{
			mlx_destroy_window(lay2->mlx_info->mlx, lay2->mlx_info->mlx_win);
			exit(0);
		}
		if (lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] == '0'
		|| lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] == 'C')
		{
			lay2->map_array[lay2->player_pos_x][lay2->player_pos_y] = '0';
			lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] = 'P';
			lay2->player_pos_x -= 1;
			lay2->number_of_steps++;
			ft_printf("Number of steps: %i \n", lay2->number_of_steps);
		}
	}
}

void	down_move(t_lay *lay2)
{
	if (lay2->map_array[lay2->player_pos_x + 1][lay2->player_pos_y] == '0'
	|| lay2->map_array[lay2->player_pos_x + 1][lay2->player_pos_y] == 'C'
	|| lay2->map_array[lay2->player_pos_x + 1][lay2->player_pos_y] == 'E' )
	{
		if (lay2->map_array[lay2->player_pos_x + 1][lay2->player_pos_y] == 'C')
			lay2->n_collected++;
		else if (lay2->map_array[lay2->player_pos_x + 1][lay2->player_pos_y]
		== 'E' && lay2->n_collected == lay2->n_2bcollected)
		{
			mlx_destroy_window(lay2->mlx_info->mlx, lay2->mlx_info->mlx_win);
			exit(0);
		}
		if (lay2->map_array[lay2->player_pos_x + 1][lay2->player_pos_y] == '0'
		|| lay2->map_array[lay2->player_pos_x + 1][lay2->player_pos_y] == 'C')
		{
			lay2->map_array[lay2->player_pos_x][lay2->player_pos_y] = '0';
			lay2->map_array[lay2->player_pos_x + 1][lay2->player_pos_y] = 'P';
			lay2->number_of_steps++;
			ft_printf("Number of steps: %i \n", lay2->number_of_steps);
			lay2->player_pos_x += 1;
		}
	}
}
