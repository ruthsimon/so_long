/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:40:38 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 22:22:11 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	populate_char(t_lay *lay, char **argv)
{
	int		fd2;
	int		y;
	char	*line;
	char	**map_array;

	map_array = NULL;
	y = 0;
	fd2 = open(argv[1], O_RDONLY);
	if (fd2 < 0)
		error_handler ("File not found\n");
	map_array = malloc(sizeof(char *) * (lay->n_row + 1));
	map_array[lay->n_row] = NULL;
	line = get_next_line(fd2);
	while (map_array[y] != NULL && line != NULL)
	{
		map_array[y] = ft_strdup(line);
		free(line);
		line = get_next_line(fd2);
		y++;
	}
	lay->map_array = map_array;
	check_layout (map_array, lay);
}

void	read_layout(int fd, char **argv, t_lay *lay)
{
	char	*line;

	line = NULL;
	lay->n_row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL && !lay->n_row)
		{
			error_handler("map is empty!!\n");
			break ;
		}
		if (line == NULL)
			break ;
		lay->n_row++;
		free(line);
	}
	close (fd);
	populate_char(lay, argv);
}
