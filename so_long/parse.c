/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:31:27 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 22:21:26 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	parse(int argc, char **argv, t_lay *lay)
{
	int	fd;

	if (argc != 2)
		error_handler("Check number of arguments!!\n");
	if (!ft_strrcmp (argv[1], ".ber", 4))
		error_handler ("Only .ber extension allowed\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_handler("File not found\n");
	check_map(fd, argv, lay);
}

void	check_map(int fd, char **argv, t_lay *lay)
{
	read_layout(fd, argv, lay);
}
