NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

AR = ar rcs

RM = rm -f

SRCS =	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strcasencmp.c \
	ft_strcasecmp.c \
	ft_strsfree.c \
	ft_strlen.c \
	ft_strslen.c \
	ft_strcat.c \
	ft_strcpy.c \
	ft_strncat.c \
	ft_strchr.c \
	ft_intchr.c \
	ft_strnchr.c \
	ft_strrchr.c \
	ft_strchrnul.c \
	ft_strstr.c \
	ft_strcasestr.c \
	ft_strnstr.c \
	ft_intlen.c \
	ft_ulonglen.c \
	ft_uintlen.c \
	ft_putstr.c \
	ft_putnstr.c \
	ft_isalpha.c \
	ft_islower.c \
	ft_isupper.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strtoupper.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_strrtrim.c \
	ft_atoi.c \
	ft_strtol.c \
	ft_strtoi.c \
	ft_striteri.c \
	ft_itoa.c \
	ft_utoa.c \
	ft_ctos.c \
	ft_ultobase.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_print_array_str.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strlcpy.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strsjoin.c \
	ft_strlcat.c

BONUS_SRCS =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstiter.c \
		ft_lstmap.c

SRCS_DIR = ./

INCLUDES = ./

GNL_INCLUDES = get_next_line/

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS_SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(GNL_INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME:.a=.so)

re: clean all

.PHONY: bonus all clean fclean re
