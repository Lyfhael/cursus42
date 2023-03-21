# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 12:55:45 by hateisse          #+#    #+#              #
#    Updated: 2023/03/21 19:08:39 by hateisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CLFAGS = -Wall -Wextra -Werror -g3

AR = ar rcs

RM = rm -f

SRCS_DIR = ./srcs/

SRCS_FILES =	main.c \
				error_handler.c \
				flood_fill.c map_parser.c \
				map_validity_checker.c \
				utils.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

INCLUDES = ./includes/

OBJS = $(SRCS:.c=.o)

LFT = libft.a

LFT_DIR = ./libft

MLX_DIR = ./mlx

GNL_DIR = $(LFT_DIR)/get_next_line

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(OBJS) -L$(LFT_DIR) -lft -L$(MLX_DIR) -lmlx -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 $(CFLAGS) -I$(MLX_DIR) -I$(INCLUDES) -I$(LFT_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	make $@ -C $(LFT_DIR)
	make $@ -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	make $@ -C $(LFT_DIR)
	make $@ -C $(MLX_DIR)
	$(RM) $(NAME) $(LFT)

re: clean all

.PHONY: all clean fclean re