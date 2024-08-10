/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:58:45 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 22:22:59 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>
#include "../get_next_line/get_next_line.h"
#include "../mlx/mlx.h"

typedef struct ml_info
{
	void	*mlx;
	void	*mlx_win;
	void	*img_player;
	void	*img_wall;
	void	*img_coin;
	void	*img_exit;
	int		player_width;
	int		player_height;
	int		wall_width;
	int		wall_height;
	int		coin_width;
	int		coin_height;
	int		exit_width;
	int		exit_height;
	char	*player_path ;
	char	*wall_path;
	char	*coin_path ;
	char	*exit_path ;
}	t_mlx_info;

typedef struct s_lay
{
	int			n_row;
	int			n_column;
	int			n_players;
	int			n_ghost;
	int			n_exit;
	int			n_2bcollected;
	int			n_collected;
	char		**map_array;
	int			player_pos_x;
	int			player_pos_y;
	t_mlx_info	*mlx_info;
	int			number_of_steps;
}	t_lay;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	flag;
}	t_enemy;

//main 
void	parse(int argc, char **argv, t_lay *lay);

//check map
void	set_newmlx(t_lay *lay);
void	set_newlay(t_lay *lay);
void	error_handler(char *msg);
void	check_map(int fd, char **argv, t_lay *lay);
int		ft_strrcmp(char *str1, char *str2, int i);

//parse
void	parse(int argc, char **argv, t_lay *lay);

//map
void	read_layout(int fd, char **argv, t_lay *lay);
void	check_layout(char **map_array, t_lay *lay);

//path
void	check_path(char **map_array, t_lay *lay);
int		is_validposition(int x, int y, t_lay *lay);
void	invalid_path(char **map_array, char **visited);
void	dfs(int x, int y, t_lay *lay, char **visited);

//game
void	init_game(t_lay *lay);
void	render(t_lay *lay, t_mlx_info *info);
void	right_move(t_lay *lay2);
void	left_move(t_lay *lay2);
void	up_move(t_lay *lay2);
void	down_move(t_lay *lay2);

//movements
int		movements(int keycode, void *map);
int		close_window(int keycode, void *mlx, void *mlx_win);

//find_player
void	find_pos_player(char **map_array, t_lay *lay);