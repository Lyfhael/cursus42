NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

CP = cp

SRCS =	./ft_printf.c \
		./parser/main_parser.c \
		./parser/parse_leading_symbol.c \
		./parser/parse_flag_characters.c \
		./parser/parse_width_specification.c \
		./parser/parse_precision_specification.c \
		./parser/parse_type_specification.c \
		./converter/main_convert.c \
		./converter/i_d_convert.c \
		./converter/c_convert.c \
		./converter/o_convert.c \
		./converter/p_convert.c \
		./converter/perc_convert.c \
		./converter/s_convert.c \
		./converter/u_convert.c \
		./converter/x_X_convert.c \
		./converter/add_hex_prefix.c \
		./converter/post_conversion_job.c \
		./converter/flag_characters_options_convert.c \
		./padding_handler/main_padding.c \
		./padding_handler/build_padding.c \
		./precision_handler/main_precision.c \
		./precision_handler/build_precision.c \
		./utils/free_flag_structure.c \
		./utils/init_flag_structure.c \
		./utils/is_hex_shape.c

LFT = libft.a

LFT_DIR = ./libft

INCLUDES = ./includes/

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	make -C $(LFT_DIR)
	$(CP) $(LFT_DIR)/$(LFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LFT_DIR) -c $< -o $@

clean:
	make $@ -C $(LFT_DIR)
	$(RM) $(OBJS) 

bonus: fclean $(NAME)

fclean: clean
	make $@ -C $(LFT_DIR)
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re 
