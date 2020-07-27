NAME := libft_math.a

SHELL = /bin/sh
CC = gcc
RM = rm -rf
AR = ar
ARFLAGS = -rcs
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_PATH)

.SUFFIXE:
.SUFFIXES: .c .o .h

INC_PATH = $(shell find includes -type d)
SRC_PATH = $(shell find src -type d)
OBJ_PATH = obj

vpath %.c $(foreach dir, $(SRC_PATH), $(dir):)

# Memory functions

SRC		=		ft_vector3.c			\
				ft_vec_op.c				\

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:%.c=%.o))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@$(AR) $(ARFLAGS) $@ $(OBJ)
	@echo "[OK]\t\t$(NAME) is ready"

$(OBJ_PATH):
	@mkdir -p $@
	@echo "[OK]\t\tCreated $@ directory"

$(OBJ_PATH)/%.o : %.c
	@echo "[Compiling]\t$< -> $@ ..."
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: debug
debug: CFLAGS+=-g3
debug: re

.PHONY: clean
clean:
	@$(RM) $(OBJ_PATH)
	@echo "[OK]\t\tCleaned object files"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo "[OK]\t\tRemoved $(NAME)"

.PHONY: re
re: fclean all
