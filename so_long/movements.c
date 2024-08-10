/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:37 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 21:42:13 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	close_window(int keycode, void *mlx, void *mlx_win)
{
	if (keycode == 53)
		mlx_destroy_window(mlx, mlx_win);
	exit(0);
	return (0);
}

int	movements(int keycode, void *lay)
{
	t_lay	*lay2;

	lay2 = (t_lay *)lay;
	if (keycode == 2 || keycode == 124)
		right_move(lay2);
	else if (keycode == 0 || keycode == 123)
		left_move(lay2);
	else if (keycode == 13 || keycode == 126)
		up_move(lay2);
	else if (keycode == 1 || keycode == 125)
		down_move(lay2);
	else if (keycode == 53)
	{
		mlx_destroy_window(lay2->mlx_info->mlx, lay2->mlx_info->mlx_win);
		exit(0);
	}
	mlx_clear_window(lay2->mlx_info->mlx, lay2->mlx_info->mlx_win);
	render(lay2, lay2->mlx_info);
	return (0);
}

void	set_path(t_lay *lay)
{
	lay->mlx_info-> player_path = "sprites/player.xpm";
	lay->mlx_info->wall_path = "sprites/wall.xpm";
	lay->mlx_info->coin_path = "sprites/coins.xpm";
	lay->mlx_info-> exit_path = "sprites/exit.xpm";
}

void	init_game(t_lay *lay)
{
	set_path(lay);
	lay->mlx_info->mlx = mlx_init();
	lay->mlx_info->mlx_win = mlx_new_window((lay->mlx_info->mlx),
			(lay->n_column * 32), (lay->n_row * 32), "So_long");
	lay->mlx_info->img_player = mlx_xpm_file_to_image(lay->mlx_info->mlx,
			lay->mlx_info->player_path, &(lay->mlx_info->player_width),
			&(lay->mlx_info->player_height));
	lay->mlx_info->img_wall = mlx_xpm_file_to_image(lay->mlx_info->mlx,
			lay->mlx_info->wall_path, &(lay->mlx_info->wall_width),
			&(lay->mlx_info->wall_height));
	lay->mlx_info->img_coin = mlx_xpm_file_to_image(lay->mlx_info->mlx,
			lay->mlx_info->coin_path, &(lay->mlx_info->coin_width),
			&(lay->mlx_info->coin_height));
	lay->mlx_info->img_exit = mlx_xpm_file_to_image(lay->mlx_info->mlx,
			lay->mlx_info->exit_path, &(lay->mlx_info->exit_width),
			&(lay->mlx_info->exit_height));
	if (lay->mlx_info->img_player == NULL || lay->mlx_info->img_wall == NULL
		|| lay->mlx_info->img_exit == NULL || lay->mlx_info->img_coin == NULL)
		error_handler("Error: Failed to load images.\n");
	render(lay, lay->mlx_info);
	mlx_hook(lay->mlx_info->mlx_win, 17, 0, close_window, &lay->mlx_info->mlx);
	mlx_hook(lay->mlx_info->mlx_win, 2, 0, movements, lay);
	mlx_loop(lay->mlx_info->mlx);
}
