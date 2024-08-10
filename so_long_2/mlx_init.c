/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:36:37 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 19:19:10 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	init_game(t_lay *lay)
{
	lay->mlx_info->mlx = mlx_init();
	lay->mlx_info->mlx_win = mlx_new_window((lay->mlx_info->mlx),
			(lay->n_column * 32), (lay->n_row * 32), "So_long");
	lay->mlx_info->player_path_right = "sprites/player.xpm";
	lay->mlx_info->player_path_left = "sprites/player1.xpm";
	lay->mlx_info->wall_path = "sprites/wall.xpm";
	lay->mlx_info->coin_path = "sprites/coins.xpm";
	lay->mlx_info->exit_path = "sprites/exit.xpm";
	lay->mlx_info->enemy1_path = "sprites/enemy4.xpm";
	load_images(lay);
	render(lay);
	mlx_hook(lay->mlx_info->mlx_win, 17, 0, close_window, &lay->mlx_info->mlx);
	mlx_hook(lay->mlx_info->mlx_win, 2, 0, movements, lay);
	mlx_loop_hook(lay->mlx_info->mlx, find_enemy, (void *)lay);
	mlx_loop(lay->mlx_info->mlx);
}
