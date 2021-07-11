BIN_NAME := miniRT

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .c .o .h

include includes.mk sources.mk

OBJ_FILES	=	$(SRC_FILES:%.c=%.o)
LIBS		=	ft minimath mlx_Linux m Xext X11

# ****************************** DIRS AND PATHS ****************************** #

LIB_DIR		=	lib/libft lib/minimath
MLX_DIR		=	lib/minilibx-linux

INC_DIR		=	include
SRC_DIR		=	src
OBJ_DIR		=	obj

SUB_DIRS	=	debug \
				event \
				parsing \
				rendering \
				struct \
				utils

SRC_SUBDIRS	=	$(addprefix $(SRC_DIR)/, $(SUB_DIRS))

INC			=	$(addprefix $(INC_DIR)/, $(INC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

INC_PATHS	=	$(INC_DIR) $(MLX_DIR) \
				$(addsuffix /$(INC_DIR), $(LIB_DIR))

LIB_PATHS	=	$(LIB_DIR) $(MLX_DIR)

VPATH		=	$(SRC_DIR) $(SRC_SUBDIRS)

# *************************** COMPILING AND FLAGS **************************** #

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(foreach path, $(INC_PATHS), -I $(path))
LDFLAGS		=	$(foreach path, $(LIB_PATHS), -L $(path))
LDLIBS		=	$(foreach lib, $(LIBS), -l $(lib))

DEBUG_CFLAGS = -g3 -D DEBUG

# ********************************** RULES *********************************** #

all: $(BIN_NAME)

# INSTALL #

install :
	#sudo apt-get update && apt-get install libxext-dev libbsd-dev
	@$(foreach path, $(LIB_PATHS), make -C $(path);)

re-install :
	@$(foreach lib, $(LIB_DIR), make -C $(lib) fclean;)
	@make -C $(MLX_DIR) clean
	@make install

# OBJ DIR #

$(OBJ_DIR):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_DIR)/%.o: %.c $(INC)
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

# LINKING #

$(BIN_NAME): $(OBJ_DIR) $(OBJ) $(INC)
	@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "\nOK\t\t$@ is ready"

# DEBUG #

show:
	@echo "VPATH: $(VPATH)"
	@echo "INC_PATHS: $(INC_PATHS)"
	@echo "LIB_PATHS: $(LIB_PATHS)"

# Debug build for gdb debugging #

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: re
	@echo "DEBUG\t\tDebug build done"

check_leaks: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./miniRT scenes/sphere1.rt

# CLEAN #

clean:
	@$(foreach lib, $(LIB_DIR), make -C $(lib) clean;)
	@$(RM) -rf $(OBJ_DIR)
	@echo "Cleaned\t\tobject files"

fclean: clean
	@$(RM) -f $(BIN_NAME)
	@echo "Removed\t\t$(BIN_NAME)"

re: fclean all

.PHONY: all install re-install show debug check_leaks clean fclean re
