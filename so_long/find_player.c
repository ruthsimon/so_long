/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:56:04 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 22:10:54 by rsimon           ###   ########.fr       */
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
