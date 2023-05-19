# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 18:07:52 by hateisse          #+#    #+#              #
#    Updated: 2023/05/19 03:22:55 by hateisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

################################################################################
#                                                                              #
#                                                                              #
#                                 VARIABLES                                    #
#                                                                              #
#                                                                              #
################################################################################

SRCS_DIR				=	srcs/

PARSING_DIR				=	parsing/

PARSING					=	parse_arguments.c

ERROR_HANDLING_DIR		=	error_handling/

ERROR_HANDLING			=	error_printing.c

PTHREAD_HANDLING_DIR	=	pthread_handling/

PTHREAD_HANDLING		=	launch_threads.c

STRUCT_UTILS_DIR		=	struct_utils/

STRUCT_UTILS			=	t_philos_utils.c	\
							t_philos_init.c		\
							init_mutex.c

PHILOS_ACTIONS_DIR		=	philos_actions/

PHILOS_ACTIONS			=	eat.c				\
							think.c				\
							sleep.c				\
							escape.c			\
							utils.c				\
							fork_handling.c		\
							death_handling.c	\

CC					=	cc

CFLAGS				+= -Wall -Werror -Wextra -MMD -MP -c -g3

INCLUDES			=	-I./includes/
INCLUDES			+=	-I./libft/
INCLUDES			+=	-I./libft/get_next_line/

LIB_DIR				=	-L./libft/

BUILD				= .build/

SRCS				+=	$(addprefix $(PARSING_DIR), $(PARSING))
SRCS				+=	$(addprefix $(ERROR_HANDLING_DIR), $(ERROR_HANDLING))
SRCS				+=	$(addprefix $(PTHREAD_HANDLING_DIR), $(PTHREAD_HANDLING))
SRCS				+=	$(addprefix $(STRUCT_UTILS_DIR), $(STRUCT_UTILS))
SRCS				+=	$(addprefix $(PHILOS_ACTIONS_DIR), $(PHILOS_ACTIONS))

SRCS				+=	main.c

OBJ					=	$(addprefix $(BUILD), $(SRCS:.c=.o))

DEPS				= 	$(OBJ:.o=.d)

DIRS				=	$(addprefix $(BUILD), $(PARSING_DIR))
DIRS				+=	$(addprefix $(BUILD), $(ERROR_HANDLING_DIR))
DIRS				+=	$(addprefix $(BUILD), $(PTHREAD_HANDLING_DIR))
DIRS				+=	$(addprefix $(BUILD), $(STRUCT_UTILS_DIR))
DIRS				+=	$(addprefix $(BUILD), $(PHILOS_ACTIONS_DIR))


LGREY				=	\033[38;5;249m
LGREEN				=	\033[38;5;28m
LBLUE				=	\033[38;5;67m
NC					=	\033[0m
BLUE1				=	\033[38;5;72m
GO_END_LINE			=	\033[K
LPURPLE				=	\033[38;5;103m

SCRIPT_SUPPR		=	suppr.txt

################################################################################
#                                                                              #
#                                                                              #
#                                 FUNCTIONS                                    #
#                                                                              #
#                                                                              #
################################################################################

define makeprint
	echo -n "$(LGREY)$1>$(LPURPLE)$2$(NC)$(LGREY)[$(NC)$(LGREEN)$3$(LGREY)]$(NC)                                   \r"
endef

################################################################################
#                                                                              #
#                                                                              #
#                                   RULES                                      #
#                                                                              #
#                                                                              #
################################################################################

all:	$(NAME)

libft:
	@make -C libft > /dev/null

libft/libft.a: libft


$(BUILD):
	@mkdir $(BUILD) $(DIRS)

$(NAME):	libft/libft.a $(BUILD)  $(OBJ)
	@echo "$(LGREEN)OBJECT FILES COMPILED                                    $(NC)"
	@$(CC) -Wall -Werror -Wextra $(OBJ) $(LIB_DIR) -lft -o $(NAME)
	@echo "$(LGREEN)MINISHELL COMPILED                                        $(NC)"
	@tput cnorm

$(BUILD)%.o:	$(SRCS_DIR)%.c Makefile 
	@tput civis
	@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ > /dev/null || $(call makeprint,"Compiling ", "$@" ,"KO")
	@$(call makeprint,"Compiling ", "$@" ,"OK")

launch: all
	@valgrind --leak-check=full --tool=helgrind --track-origins=yes --quiet --show-leak-kinds=all --track-fds=yes ./philo

clean:
	@rm -rf $(BUILD)
	@echo "================cleaned================"

fclean:	clean
	@rm -f suppr.txt
	@make fclean -C libft > /dev/null
	@rm -rf $(NAME)
	
re:	fclean all
	
.PHONY:	clean fclean all re libft

-include $(DEPS)