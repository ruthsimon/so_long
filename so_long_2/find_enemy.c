/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:12:18 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 22:14:57 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	move_enemy_right(t_lay *lay, t_enemy *enemy)
{
	if (lay->map_array[enemy->x][enemy->y + 1] == '0')
	{
		lay->map_array[enemy->x][enemy->y] = '0';
		lay->map_array[enemy->x][enemy->y + 1] = 'G';
		enemy->y += 1;
	}
	else if (lay->map_array[enemy->x][enemy->y + 1] == 'P')
	{
		mlx_destroy_window(lay->mlx_info->mlx, lay->mlx_info->mlx_win);
		exit(0);
	}
	else
		enemy->flag = -1;
}

void	move_enemy_left(t_lay *lay, t_enemy *enemy)
{
	if (lay->map_array[enemy->x][enemy->y - 1] == '0')
	{
		lay->map_array[enemy->x][enemy->y] = '0';
		lay->map_array[enemy->x][enemy->y - 1] = 'G';
		enemy->y -= 1;
	}
	else if (lay->map_array[enemy->x][enemy->y - 1] == 'P')
	{
		mlx_destroy_window(lay->mlx_info->mlx, lay->mlx_info->mlx_win);
		exit(0);
	}
	else
		enemy->flag = 1;
}

void	move_and_check_collisions(t_lay *lay)
{
	t_enemy	*current;

	current = lay->enemies;
	while (current != NULL)
	{
		if (current->flag == 1)
		{
			move_enemy_right(lay, current);
		}
		else
			move_enemy_left(lay, current);
		slower();
		current = current->next;
	}
}

int	find_enemy(t_lay *lay)
{
	move_and_check_collisions(lay);
	mlx_clear_window(lay->mlx_info->mlx, lay->mlx_info->mlx_win);
	render(lay);
	return (1);
}
