/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:14:39 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 22:07:21 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	list_size(t_enemy *enemy)
{
	t_enemy	*tmp;
	int		size;

	size = 0;
	tmp = enemy;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

t_enemy	*create_enemy(int x, int y, int flag)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	if (new_enemy != NULL)
	{
		set_enemy(new_enemy);
		new_enemy->x = x;
		new_enemy->y = y;
		new_enemy->flag = flag;
		new_enemy->next = NULL;
	}
	return (new_enemy);
}

void	insert_enemy2node(t_enemy **enemy_head, int x, int y, int flag)
{
	t_enemy	*new_node;

	new_node = create_enemy(x, y, flag);
	if (enemy_head == NULL)
		enemy_head = &new_node;
	else
	{
		new_node->next = *enemy_head;
		*enemy_head = new_node;
	}
}

int	find_ene(t_lay *lay)
{
	int	x1;
	int	y1;

	y1 = 0;
	x1 = 0;
	while (lay->map_array[x1] != NULL)
	{
		y1 = 0;
		while (lay->map_array[x1][y1] != '\0')
		{
			if (lay->map_array[x1][y1] == 'G')
			{
				insert_enemy2node(&lay->enemies, x1, y1, 1);
				lay->n_ghost++;
			}
			y1++;
		}
		x1++;
	}
	list_size(lay->enemies);
	return (0);
}
