/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:44 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 22:13:24 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	end_game(t_lay *lay2)
{
	mlx_destroy_window(lay2->mlx_info->mlx, lay2->mlx_info->mlx_win);
	exit(0);
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
	else if (lay2->map_array[lay2->player_pos_x][lay2->player_pos_y + 1] == 'G')
		end_game(lay2);
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
	else if (lay2->map_array[lay2->player_pos_x][lay2->player_pos_y - 1] == 'G')
		end_game(lay2);
}

void	up_move(t_lay *lay2)
{
	if (lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] == '0'
	|| lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] == 'C'
	|| lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] == 'E')
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
	else if (lay2->map_array[lay2->player_pos_x - 1][lay2->player_pos_y] == 'G')
		end_game(lay2);
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
	else if (lay2->map_array[lay2->player_pos_x + 1][lay2->player_pos_y] == 'G')
		end_game(lay2);
}
