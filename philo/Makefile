# PATH VARIABLES
SRC_PATH = src/
OBJ_PATH = obj/
BIN_PATH = ./bin/
INCLUDE = include/

NAME = $(BIN_PATH)philo

CC = gcc -Wall -Wextra -Werror -g3
LIB = -lpthread

# BASH COMMANDS
MKDIR =	mkdir -p

SRCS =	main.c \
		args_check.c \
		data_destroy.c \
		data_init.c \
		dining_ancillary_funcs.c \
		dining.c \
		solo_dining.c \
		utils_data_race.c \
		utils_number_handling.c \
		utils_printing.c \
		utils_time.c
SRCS_PREFIXED = $(addprefix $(SRC_PATH), $(SRCS))
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_PREFIXED = $(addprefix $(OBJ_PATH), $(OBJS))

all:	make_dirs $(NAME)

make_dirs:
	@$(MKDIR) $(OBJ_PATH)
	@$(MKDIR) $(BIN_PATH)

$(NAME):	$(OBJS_PREFIXED)
	$(CC) -I $(INCLUDE) $(OBJS_PREFIXED) -o $(NAME) $(LIB)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	$(CC) -c $< -I $(INCLUDE) -o $@

run:	all
	$(NAME) $(ARGS)

valgrind:	all
	valgrind --leak-check=full --show-leak-kinds=all --quiet $(NAME) $(ARGS)

hellgrind:	all
	valgrind --quiet --tool=helgrind $(NAME) $(ARGS)

clean:
	rm -rf $(OBJS_PREFIXED)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: make_dirs clean fclean re