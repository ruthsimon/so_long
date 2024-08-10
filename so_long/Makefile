# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2024/02/19 12:55:58 by rsimon            #+#    #+#              #
# #    Updated: 2024/02/27 19:26:48 by rsimon           ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

# Executable Name
NAME = so_long

# Compiler
CC = cc

# Compiler Flags
CFLAGS = -Wall -Wextra -Werror -g3

# Directories
LIBFT_DIR = ./libft
GET_NEXT_LINE_DIR = ./get_next_line
MLX_DIR = ./mlx/
PRINTF_DIR = ./ft_printf

# Libraries
LIBFT_LIB = $(LIBFT_DIR)/libft.a
GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_DIR)/get_next_line.a
MLX_LIB = $(MLX_DIR)/libmlx.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# Source files
SRCS = main.c check_map.c map.c path.c game.c movements.c parse.c read_layout.c find_player.c

# Object files
OBJS =	$(SRCS:.c=.o)
		



# Build Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(GET_NEXT_LINE_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(OBJS) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB) $(MLX_LIB) $(PRINTF_LIB) -o $(NAME) -Lmlx -lmlx -framework OpenGL -framework AppKit
# $(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# $(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB) $(MLX_LIB) -o $(NAME)


%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
# Clean Rules
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
# $(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

	# Assuming there's an fclean rule in the mlx directory Makefile
# $(MAKE) -C $(MLX_DIR) fclean

re: fclean all


























# LIBFT= ./libft
# LIBFT_LIB = libft/libft.a
# GET_NEXT_LINE = get_next_line
# GET_NEXT_LINE_LIB = get_next_line/get_next_line.a
# MLX = ./mlx

# NAME = so_long

# CC = cc 

# CFLAGS = -Wall -Wextra -Werror

# SRCS =  main.c check_map.c map.c path.c game.c

# SRCS_BONUS =

# OBJS = $(SRCS:.c=.o)

# %.o: %.c
# 	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	   

# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	 	$(MAKE) -C $(LIBFT)
# 	 	$(MAKE) -C $(GET_NEXT_LINE)
# 	 $(MAKE) -C $(MLX)
# 	 $(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB) -o $(NAME)
# #   $(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

	

# bonus: $(OBJS) $(OBJS_BONUS)
# 	ar rcs $(NAME) $^

# clean:
# 	rm -f $(OBJS)
# 	rm -f libft/*.o

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re bonus


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:55:58 by rsimon            #+#    #+#              #
#    Updated: 2024/02/27 19:26:48 by rsimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# # Executable Name
# NAME = so_long

# # Compiler
# CC = cc

# # Compiler Flags
# CFLAGS = -Wall -Wextra -Werror

# # Directories
# LIBFT_DIR = ./libft/
# GET_NEXT_LINE_DIR = ./get_next_line/
# MLX_DIR = ./mlx/

# # Libraries
# LIBFT_LIB = $(LIBFT_DIR)/libft.a
# GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_DIR)/get_next_line.a

# # Source files
# SRCS = main.c check_map.c map.c path.c game.c

# # Object files
# OBJS = $(SRCS:.c=.o) $(LIBFT_DIR:.c=.o) $(GET_NEXT_LINE_DIR:.c=.o) $(MLX_DIR:.c=.o)

# # Compilation Rule for Object Files
# # %.o: %.c
# # 	$(CC) $(CFLAGS) -Imlx -c $< -o $@

# # Build Rules
# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(GET_NEXT_LINE_LIB) -o $(NAME)

# bonus: $(OBJS) $(OBJS_BONUS)
# 	ar rcs $(NAME) $^

# # Clean Rules
# clean:
# 	rm -f $(OBJS)
# 	$(MAKE) -C $(LIBFT_DIR) clean
# 	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean

# fclean: clean
# 	rm -f $(NAME)
# 	$(MAKE) -C $(LIBFT_DIR) fclean
# 	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean

# re: fclean all

# .PHONY: all clean fclean re bonus

