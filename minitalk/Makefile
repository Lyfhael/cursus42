# NAME = minitalk

# CC = gcc

# CFLAGS = -Wall -Wextra -Werror

# AR = ar rcs

# RM = rm -f

# SRCS_DIR = ./srcs/

# SRCS_F = server/main.c

# SRCS = $(addprefix $(SRCS_DIR), $(SRCS_F))

# INCLUDES = ./includes/

# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(GNL_INCLUDES) -c $< -o $@

# clean:
# 	$(RM) $(OBJS) $(BONUS_OBJS)

# fclean: clean
# 	$(RM) $(NAME) $(NAME:.a=.so)

# re: clean all

# .PHONY: bonus all clean fclean re


server:
	gcc -Wall -Werror -Wextra main.c -o server

client:
