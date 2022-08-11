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

SRCS =	philosophers-dinner.c
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
	$(CC) -c $< -I $(INCLUDE) -o $@ $(LIB)

run:	all
	$(BIN_PATH)$(NAME)

valgrind:	all
	valgrind --leak-check=full --show-leak-kinds=all --quiet $(BIN_PATH)$(NAME)

clean:
	rm -rf $(OBJS_PREFIXED)

fclean: clean
	rm -rf $(BIN_PATH)$(NAME)

re: fclean all

.PHONY: make_dirs clean fclean re