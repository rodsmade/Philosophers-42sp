NAME = philo

SRC_PATH = src/
OBJ_PATH = obj/
BIN_PATH = bin/
INCLUDE = ./include/

CC = gcc -Wall -Wextra -Werror
LIB = -lpthread

# BASH COMMANDS
MKDIR =	mkdir -p

SRCS = philosophers.c
SRCS_PREFIXED = $(addprefix $(SRC_PATH), $(SRCS))
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_PREFIXED = $(addprefix $(OBJ_PATH), $(OBJS))

all:	make_dirs $(NAME)

make_dirs:
	@$(MKDIR) $(OBJ_PATH)
	@$(MKDIR) $(BIN_PATH)

$(NAME):	$(OBJS_PREFIXED)
	$(CC) -I $(INCLUDE) $(OBJS_PREFIXED) -o $(BIN_PATH)$(NAME) $(LIB)

# não sei se precisa das libs pra gerar os objeto kkkkk caraio 
$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	$(CC) -c $< -I $(INCLUDE) -o $@ $(LIB)