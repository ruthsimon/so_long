/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:52:29 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 18:29:26 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	check_components_and_count(t_lay *lay, int i,
	int *players, int *exits)
{
	int	c;

	c = 0;
	while (lay->map_array[i][c] != '\0')
	{
		if (!ft_strchr("10PCEG", lay->map_array[i][c]))
			error_handler("There are invalid characters!!\n");
		if (lay->map_array[i][0] != '1'
		|| lay->map_array[i][lay->n_column - 1] != '1')
			error_handler("Border is open!!\n");
		if (lay->map_array[i][c] == 'C')
			lay->n_2bcollected++;
		if (lay->map_array[i][c] == 'P')
			(*players)++;
		if (lay->map_array[i][c] == 'E')
			(*exits)++;
		c++;
	}
}

void	check_rectangular(char **map_array, t_lay *lay, int i)
{
	if (ft_strlen(map_array[i]) != (size_t)lay->n_column)
		error_handler("it is not rectangular\n");
}

void	check_conditions(int players, int exits, t_lay *lay)
{
	if (players > 1)
		error_handler("More than 1 player!!\n");
	if (exits > 1)
		error_handler("More than 1 exit!!\n");
	if (exits == 0)
		error_handler("There is no exit!!\n");
	if (lay->n_2bcollected == 0)
		error_handler("There should be at least one collectible!!\n");
	if (players == 0 || lay->n_2bcollected == 0)
		error_handler("Please make sure there's a player or coins!!\n");
}

void	check_layout(char **map_array, t_lay *lay)
{
	int	i;
	int	players;
	int	exits;

	i = 0;
	players = 0;
	exits = 0;
	lay->n_column = ft_strlen(map_array[0]);
	while (map_array[i] != NULL)
	{
		check_components_and_count(lay, i, &players, &exits);
		check_rectangular(map_array, lay, i);
		i++;
	}
	check_conditions(players, exits, lay);
	check_path(map_array, lay);
}
