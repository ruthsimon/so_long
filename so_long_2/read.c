/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:13:33 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 22:09:10 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	slower(void)
{
	size_t	i;

	i = 0;
	while (i < 10000000)
		i++;
}

void	count_rows(int fd, t_lay *lay)
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
	close(fd);
}

void	read_layout(int fd, char **argv, t_lay *lay)
{
	char	*line;
	char	**map_array;
	int		fd2;
	int		y;

	map_array = NULL;
	y = 0;
	count_rows(fd, lay);
	fd2 = open(argv[1], O_RDONLY);
	if (fd2 < 0)
		error_handler("File not found\n");
	map_array = malloc(sizeof(char *) * (lay->n_row + 1));
	map_array[lay->n_row] = NULL;
	line = get_next_line(fd);
	while (map_array[y] != NULL && line != NULL)
	{
		map_array[y] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	lay->map_array = map_array;
	check_layout(map_array, lay);
}
