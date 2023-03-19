# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 12:55:45 by hateisse          #+#    #+#              #
#    Updated: 2023/03/19 20:39:58 by hateisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CLFAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SRCS_DIR = ./srcs/

SRCS_FILES =	main.c parser.c stack_operations.c linked_list_functions.c linked_list_functions2.c sort.c \
				argv_sanitize.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

INCLUDES = ./includes/

OBJS = $(SRCS:.c=.o)

LFT = libft.a

LFT_DIR = ./libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LFT_DIR)
	cp $(LFT_DIR)/$(LFT) $(LFT)
	$(CC) $(OBJS) -L$(LFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 $(CFLAGS) -I$(INCLUDES) -I$(LFT_DIR) -c $< -o $@

clean:
	make $@ -C $(LFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make $@ -C $(LFT_DIR)
	$(RM) $(NAME) $(LFT)

re: clean all

.PHONY: all clean fclean re