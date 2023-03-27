# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 12:55:45 by hateisse          #+#    #+#              #
#    Updated: 2023/03/27 18:05:51 by hateisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

# CLFAGS = -Wall -Wextra -Werror -g3

CFLAGS = -g3

RM = rm -f

SRCS_DIR = ./srcs/

SRCS_FILES =	main.c \
				handle_fork_struct.c \
				load_files.c \
				ft_error.c \
				check_command_path.c
				
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

INCLUDES = ./includes/

OBJS = $(SRCS:.c=.o)

LFT = libft.a

LFT_DIR = ./libft

GNL_DIR = $(LFT_DIR)/get_next_line

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LFT_DIR)
	$(CC) $(OBJS) -L$(LFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 $(CFLAGS) -I$(INCLUDES) -I$(LFT_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	make $@ -C $(LFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make $@ -C $(LFT_DIR)
	$(RM) $(NAME) $(LFT)

re: clean all

.PHONY: all clean fclean re