/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:52:40 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 22:15:39 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	error_handler(char *msg)
{
	ft_putstr_fd (msg, 1);
	exit (EXIT_FAILURE);
}

int	ft_strrcmp(char *str1, char *str2, int i)
{
	int	len_1;
	int	x;

	x = 0;
	len_1 = ft_strlen(str1);
	len_1 = len_1 - i;
	while (str2[x])
	{
		if (str1[len_1] == str2[x])
		{
			x++;
			len_1++;
		}
		else
			return (0);
	}
	if (x == i)
		return (1);
	else
		return (0);
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
}

void	set_enemy(t_enemy *enemy)
{
	enemy->x = 0;
	enemy->y = 0;
	enemy->flag = 0;
}

void	set_newmlx(t_lay *lay)
{
	lay->mlx_info->mlx = NULL;
	lay->mlx_info->mlx_win = NULL;
	lay->mlx_info->img_player = NULL;
	lay->mlx_info->img_wall = NULL;
	lay->mlx_info->img_coin = NULL;
	lay->mlx_info->img_exit = NULL;
	lay->mlx_info->player_width = 0;
	lay->mlx_info->player_height = 0;
	lay->mlx_info->wall_width = 0;
	lay->mlx_info->wall_height = 0;
	lay->mlx_info->coin_width = 0;
	lay->mlx_info->coin_height = 0;
	lay->mlx_info->exit_width = 0;
	lay->mlx_info->exit_height = 0;
	lay->mlx_info->player_path = NULL;
	lay->mlx_info->wall_path = NULL;
	lay->mlx_info->coin_path = NULL;
	lay->mlx_info->exit_path = NULL;
}
