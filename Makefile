NAME = win95keycheck

SRC_DIR = src/
OBJ_DIR = objs/
INC_DIR = includes/

INCS = -I$(INC_DIR)

SRC =	main.c \
		helpers.c

OBJ := $(SRC:%.c=%.o)
DEP := $(SRC:%.c=%.d)

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
DEPS = $(addprefix $(OBJ_DIR), $(DEP))

CCFLAGS = -Wall -Wextra -Werror -Wconversion -O2

all: $(NAME)

$(NAME): $(SRCS) $(OBJ_DIR) $(OBJS)
	@gcc $(CCFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(CCFLAGS) -MMD $(INCS) $< -c -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(DEPS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)