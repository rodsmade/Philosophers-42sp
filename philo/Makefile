# gcc -g3 philo/philosophers-dinner.c -lpthread
# valgrind --leak-check=full --show-leak-kinds=all --quiet ./a.out

NAME = philo

SRC_PATH = src/
OBJ_PATH = obj/
BIN_PATH = ./bin/
INCLUDE = include/

CC = gcc -Wall -Wextra -Werror -g3
LIB = -lpthread

# BASH COMMANDS
MKDIR =	mkdir -p

SRCS =	philosophers-dinner.c \
		args_check.c \
		aux_eating.c \
		data_destroy.c \
		data_init.c \
		solo_dining.c \
		utils_data-race.c \
		utils_number_handling.c \
		utils_printing.c \
		utils_timestamp.c
SRCS_PREFIXED = $(addprefix $(SRC_PATH), $(SRCS))
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_PREFIXED = $(addprefix $(OBJ_PATH), $(OBJS))

all:	make_dirs $(NAME)

make_dirs:
	@$(MKDIR) $(OBJ_PATH)
	@$(MKDIR) $(BIN_PATH)

$(NAME):	$(OBJS_PREFIXED)
	$(CC) -I $(INCLUDE) $(OBJS_PREFIXED) -o $(BIN_PATH)$(NAME) $(LIB)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	$(CC) -c $< -I $(INCLUDE) -o $@

run:	all
	$(BIN_PATH)$(NAME) $(ARGS)

valgrind:	all
	valgrind --leak-check=full --show-leak-kinds=all --quiet $(BIN_PATH)$(NAME) $(ARGS)

hellgrind:	all
	valgrind --quiet --tool=helgrind $(BIN_PATH)$(NAME) $(ARGS)

clean:
	rm -rf $(OBJS_PREFIXED)

fclean: clean
	rm -rf $(BIN_PATH)$(NAME)

re: fclean all

.PHONY: make_dirs clean fclean re