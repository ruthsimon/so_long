# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 17:04:53 by rsimon            #+#    #+#              #
#    Updated: 2024/02/19 21:10:32 by rsimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = get_next_line.a

# CC = cc 

# CFLAGS = -Wall -Wextra -Werror

# SRCS = get_next_line.c get_next_line_utils.c 

# SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c 

# OBJS = $(SRCS:.c=.o)

# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# all: $(OBJS) $(OBJS_BONUS)

# $(NAME): $(OBJS)
# 	ar rcs $@ $^
# # $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# bonus: $(OBJS_BONUS)
#  	ar rcs $(NAME) $^ 
# # $(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME)

# clean:
# 	rm -f $(OBJS) $(OBJS_BONUS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re bonus

NAME = get_next_line.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c 
SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c 
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(NAME) $(OBJS_BONUS)
	ar rcs $(NAME) $^ 

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
