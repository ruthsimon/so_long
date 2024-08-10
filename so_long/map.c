/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:52:29 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 22:19:45 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	check(int players, int exits, t_lay *lay)
{
	if (players > 1)
		error_handler("More than 1 player!!\n");
	if (exits > 1)
		error_handler("More than 1 exit!!\n");
	if (exits == 0)
		error_handler("There is no exit!!\n");
	if (lay->n_2bcollected == 0)
		error_handler("There should be atleast one collectible!!\n");
	if (players == 0 || lay->n_2bcollected == 0)
		error_handler("Please make sure there's a player or coins!!\n");
	check_path(lay->map_array, lay);
}

void	check_alphapets(char c)
{
	if (!ft_strchr("10PCE", c))
		error_handler("There are invalid characters!!\n");
}

void	check_players_exits_collectibles(char **map_array, t_lay *lay)
{
	int	i;
	int	players;
	int	exits;
	int	c;

	i = 0;
	players = 0;
	exits = 0;
	while (map_array[i] != NULL)
	{
		c = 0;
		while (map_array[i][c] != '\0')
		{
			check_alphapets(map_array[i][c]);
			if (map_array[i][c] == 'C')
				lay->n_2bcollected++;
			c++;
		}
		if (ft_strchr(map_array[i], 'P'))
			players++;
		if (ft_strchr(map_array[i], 'E'))
			exits++;
		i++;
	}
	check(players, exits, lay);
}

void	check_layout(char **map_array, t_lay *lay)
{
	int	i;

	i = 0;
	lay->n_column = ft_strlen(map_array[0]);
	while (map_array[i] != NULL)
	{
		if (ft_strchr(map_array[0], '0'))
			error_handler("upper border not closed!!\n");
		if (map_array[i][0] != '1' || map_array[i][lay->n_column - 1] != '1')
			error_handler("Border is open!!\n");
		if (ft_strlen(map_array[i]) != (size_t)lay->n_column)
			error_handler("it is not rectangular\n");
		i++;
	}
	check_players_exits_collectibles(lay->map_array, lay);
}
