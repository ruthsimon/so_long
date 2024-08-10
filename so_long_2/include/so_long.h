/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:58:45 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 22:16:05 by rsimon           ###   ########.fr       */
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
	void	*img_player_right;
	void	*img_player_left;
	void	*img_wall;
	void	*img_coin;
	void	*img_exit;
	void	*img_enemy1;
	int		player_width_right;
	int		player_height_right;
	int		wall_width;
	int		wall_height;
	int		coin_width;
	int		coin_height;
	int		exit_width;
	int		exit_height;
	int		enemy1_width;
	int		enemy1_height;
	char	*player_path_right;
	char	*player_path_left;
	char	*wall_path;
	char	*coin_path ;
	char	*exit_path ;
	char	*enemy1_path;
}	t_mlx_info;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				flag;
	struct s_enemy	*next;
}	t_enemy;

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
	t_enemy		*enemies;
	int			number_of_steps;
	int			face_flag;
}	t_lay;

//main 
void	parse(int argc, char **argv, t_lay *lay);

//check map
void	set_newmlx(t_lay *lay);
void	set_newlay(t_lay *lay);
void	error_handler(char *msg);
void	check_map(int fd, char **argv, t_lay *lay);
void	set_enemy(t_enemy *enemy);

//map
void	read_layout(int fd, char **argv, t_lay *lay);

//path
void	check_path(char **map_array, t_lay *lay);
int		find_enemy(t_lay *lay);

//game
void	init_game(t_lay *lay);
void	check_layout(char **map_array, t_lay *lay);

//movements
void	render(t_lay *lay);
int		movements(int keycode, void *map);
int		close_window(int keycode, void *mlx, void *mlx_win);
void	right_move(t_lay *lay2);
void	left_move(t_lay *lay2);
void	up_move(t_lay *lay2);
void	down_move(t_lay *lay2);
void	load_images(t_lay *lay);

//find player 
void	find_pos_player(char **map_array, t_lay *lay);
void	render_steps(t_lay *lay);

//enemy
int		find_ene(t_lay *lay);

//parse
void	parse(int argc, char **argv, t_lay *lay);
void	check_map(int fd, char **argv, t_lay *lay);

//find_enemy
int		find_enemy(t_lay *lay);

//read
void	slower(void);
