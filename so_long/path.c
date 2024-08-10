/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:23:04 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 22:30:10 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	is_validposition(int x, int y, t_lay *lay)
{
	if (x >= 0 && y >= 0 && lay->n_row > y && lay->n_column > x)
		return (1);
	else
		return (0);
}

void	invalid_path(char **map_array, char **visited)
{
	int	i;
	int	c;

	i = 0;
	while (map_array[i] != NULL)
	{
		c = 0;
		while (map_array[i][c] != '\0')
		{
			if (map_array[i][c] == 'C' || map_array[i][c] == 'E')
			{
				if (visited[i][c] != '1')
				{
					error_handler("invalid path!!!!\n");
					return ;
				}
			}
			c++;
		}
		i++;
	}
}

void	dfs(int x, int y, t_lay *lay, char **visited)
{
	int	s;
	int	new_x;
	int	new_y;
	int	dx[4];
	int	dy[4];

	ft_memcpy(dx, (int [4]){-1, 1, 0, 0}, sizeof(int) * 4);
	ft_memcpy(dy, (int [4]){0, 0, -1, 1}, sizeof(int) * 4);
	visited[x][y] = '1';
	s = 0;
	while (s < 4)
	{
		new_x = x + dx[s];
		new_y = y + dy[s];
		if (new_x >= 0 && new_x < lay->n_row && new_y >= 0
			&& new_y < lay->n_column && visited[new_x][new_y] == '0'
			&& lay->map_array[new_x][new_y] != '1')
			dfs(new_x, new_y, lay, visited);
		s++;
	}
}

void	find_player(char **map_array, t_lay *lay)
{
	char	**visited;
	int		i;

	visited = NULL;
	visited = (char **)malloc(sizeof(char *) * (lay->n_row));
	i = 0;
	while (i < lay->n_row)
	{
		visited[i] = (char *)malloc(sizeof(char) * (lay->n_column));
		ft_memset(visited[i], '0', lay->n_column);
		i++;
	}
	find_pos_player(map_array, lay);
	if (!is_validposition(lay->player_pos_x, lay->player_pos_y, lay))
	{
		error_handler("invalid position");
		return ;
	}
	dfs(lay->player_pos_x, lay->player_pos_y, lay, visited);
	invalid_path(map_array, visited);
}

void	check_path(char **map_array, t_lay *lay)
{
	find_player(map_array, lay);
}
