/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:52:07 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 18:28:09 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	ft_strrcmp(char *str1, char *str2, int i)
{
	int	len_1;
	int	x;

	len_1 = ft_strlen(str1);
	x = 0;
	len_1 = len_1 - i;
	while (str2[x])
	{
		if (str1[len_1] == str2[x])
		{
			x++;
			len_1++;
		}
		else
			return (0);
	}
	if (x == i)
		return (1);
	else
		return (0);
}

void	parse(int argc, char **argv, t_lay *lay)
{
	int	fd;

	if (argc != 2)
		error_handler("Check number of arguments!!\n");
	if (!ft_strrcmp (argv[1], ".ber", 4))
		error_handler ("Only .ber extension allowed\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_handler ("File not found\n");
	check_map(fd, argv, lay);
}

void	check_map(int fd, char **argv, t_lay *lay)
{
	read_layout(fd, argv, lay);
}
