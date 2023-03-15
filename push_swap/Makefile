# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 12:55:45 by hateisse          #+#    #+#              #
#    Updated: 2023/03/15 17:12:20 by hateisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CLFAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SRCS_DIR = ./srcs/

SRCS_FILES = main.c parser.c stack_operations.c linked_list_functions.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

INCLUDES = ./includes/

OBJS = $(SRCS:.c=.o)

LFT = libft.a

LFT_DIR = ./libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LFT_DIR)
	ls $(LFT_DIR)
	$(CP) $(LFT_DIR)/$(LFT) $(LFT)
	$(CC) $(OBJS)  -L$(LFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME:.a=.so)

re: clean all

.PHONY: all clean fclean re