NAME = miniRT

SHELL = /bin/sh
CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
IFLAGS = $(foreach dir, $(INC_PATH), -I $(dir))
LFLAGS = $(foreach dir, $(LIB_PATH), -L $(dir)) $(foreach lib, $(LIB), -l $(lib))
LFLAGS += -lXext -lX11

.SUFFIXE:
.SUFFIXES: .c .o .h

LIB_PATH = lib/libft lib/mlx
INC_PATH = $(shell find includes -type d) lib/libft/includes lib/mlx
SRC_PATH = $(shell find src -type d)
OBJ_PATH = obj

vpath %.c $(foreach dir, $(SRC_PATH), $(dir):)

LIB			=	ft mlx_Linux

SRC			= 	main.c				\
				application.c		\
				color.c				\
				coord.c				\
				display.c			\
				drawing.c			\
				exit.c				\
				exit_error.c		\
				events.c			\
				image.c				\
				objects.c			\
				parsing.c			\
				parsing_obj.c		\
				parsing_values.c	\
				parsing_view.c		\
				parsing_utils.c		\
				render.c			\
				save.c				\
				scene.c				\

OBJ			=	$(addprefix $(OBJ_PATH)/, $(SRC:%.c=%.o))

.PHONY: all
all: $(NAME)

.PHONY: install
install :
	@$(foreach dir, $(LIB_PATH), make -C $(dir);)

.PHONY: re-install
re-install :
	@make -C lib/libft fclean
	@make -C lib/mlx clean
	@make install

$(NAME): install $(OBJ_PATH) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@
	@echo "[OK]\t\t$(NAME) is ready"

$(OBJ_PATH):
	@mkdir -p $@
	@echo "[OK]\t\tCreated $@ directory"

$(OBJ_PATH)/%.o : %.c
	@echo "[Compiling]\t$< -> $@ ..."
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: debug
debug: CFLAGS+=-g3 -fsanitize=address
debug: re
	./miniRT scenes/scene.rt

# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./miniRT scenes/scene.rt

.PHONY: bonus
bonus: $(NAME)

.PHONY: clean
clean:
	@$(RM) $(OBJ_PATH)
	@$(foreach dir, $(LIB_PATH), make -C $(dir) clean;)
	@echo "[OK]\t\tCleaned object files"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@make -C lib/libft fclean
	@echo "[OK]\t\tRemoved $(NAME)"

.PHONY: re
re: fclean all
