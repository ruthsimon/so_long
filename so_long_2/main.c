/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:52:38 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 22:06:17 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_lay		*lay;
	t_enemy		*enemy;
	t_mlx_info	*mlx_info1;

	lay = malloc(sizeof(t_lay));
	set_newlay(lay);
	mlx_info1 = malloc(sizeof(t_mlx_info));
	enemy = malloc(sizeof(t_enemy));
	set_enemy(enemy);
	lay->mlx_info = mlx_info1;
	lay->enemies = enemy;
	set_newmlx(lay);
	parse(argc, argv, lay);
	find_ene(lay);
	init_game(lay);
}
