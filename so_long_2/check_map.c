/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:52:40 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 19:39:33 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	error_handler(char *msg)
{
	ft_putstr_fd (msg, 1);
	exit (EXIT_FAILURE);
}

void	set_newlay(t_lay *lay)
{
	lay->n_row = 0;
	lay->n_column = 0;
	lay->n_2bcollected = 0;
	lay->n_collected = 0;
	lay->n_exit = 0;
	lay->n_ghost = 0;
	lay->n_players = 0;
	lay->player_pos_y = 0;
	lay->player_pos_x = 0;
	lay->map_array = NULL;
	lay->mlx_info = NULL;
	lay->number_of_steps = 0;
	lay->enemies = NULL;
	lay->face_flag = 1;
}

void	set_enemy(t_enemy *enemy)
{
	enemy->x = 0;
	enemy->y = 0;
	enemy->flag = 0;
	enemy->next = NULL;
}

void	set_newmlx(t_lay *lay)
{
	lay->mlx_info->mlx = NULL;
	lay->mlx_info->mlx_win = NULL;
	lay->mlx_info->img_player_right = NULL;
	lay->mlx_info->img_player_left = NULL;
	lay->mlx_info->img_wall = NULL;
	lay->mlx_info->img_coin = NULL;
	lay->mlx_info->img_exit = NULL;
	lay->mlx_info->img_enemy1 = NULL;
	lay->mlx_info->player_width_right = 0;
	lay->mlx_info->player_height_right = 0;
	lay->mlx_info->wall_width = 0;
	lay->mlx_info->wall_height = 0;
	lay->mlx_info->coin_width = 0;
	lay->mlx_info->coin_height = 0;
	lay->mlx_info->exit_width = 0;
	lay->mlx_info->exit_height = 0;
	lay->mlx_info->enemy1_width = 0;
	lay->mlx_info->enemy1_height = 0;
	lay->mlx_info->player_path_right = NULL;
	lay->mlx_info->player_path_left = NULL;
	lay->mlx_info->wall_path = NULL;
	lay->mlx_info->coin_path = NULL;
	lay->mlx_info->exit_path = NULL;
	lay->mlx_info->enemy1_path = NULL;
}
