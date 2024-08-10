/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:37 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 21:27:16 by rsimon           ###   ########.fr       */
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
	{
		right_move(lay2);
		lay2->face_flag = 1;
	}
	else if (keycode == 0 || keycode == 123)
	{
		left_move(lay2);
		lay2->face_flag = 2;
	}
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
	render(lay2);
	return (0);
}

void	load_images(t_lay *lay)
{
	lay->mlx_info->img_player_right = mlx_xpm_file_to_image(lay->mlx_info->mlx,
			lay->mlx_info->player_path_right, &(lay->mlx_info
				->player_width_right), &(lay->mlx_info->player_height_right));
	lay->mlx_info->img_player_left = mlx_xpm_file_to_image(lay->mlx_info->mlx,
			lay->mlx_info->player_path_left, &(lay->mlx_info
				->player_width_right), &(lay->mlx_info->player_height_right));
	lay->mlx_info->img_wall = mlx_xpm_file_to_image(lay->mlx_info->mlx,
			lay->mlx_info->wall_path, &(lay->mlx_info->wall_width),
			&(lay->mlx_info->wall_height));
	lay->mlx_info->img_coin = mlx_xpm_file_to_image(lay->mlx_info->mlx,
			lay->mlx_info->coin_path, &(lay->mlx_info->coin_width),
			&(lay->mlx_info->coin_height));
	lay->mlx_info->img_exit = mlx_xpm_file_to_image(lay->mlx_info->mlx,
			lay->mlx_info->exit_path, &(lay->mlx_info->exit_width),
			&(lay->mlx_info->exit_height));
	lay->mlx_info->img_enemy1 = mlx_xpm_file_to_image(lay->mlx_info->mlx,
			lay->mlx_info->enemy1_path, &(lay->mlx_info->enemy1_width),
			&(lay->mlx_info->enemy1_height));
	if (lay->mlx_info->img_player_right == NULL || lay->mlx_info->img_wall
		== NULL || lay->mlx_info->img_exit == NULL || lay->mlx_info->img_coin
		== NULL || lay->mlx_info->img_enemy1 == NULL)
	{
		ft_printf("Error: Failed to load images.\n");
		exit(1);
	}
}
