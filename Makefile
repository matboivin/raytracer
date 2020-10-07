NAME := miniRT

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXE:
.SUFFIXES: .c .o .h

# ******************************** CC AND FLAGS ****************************** #

CC = gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS		=	$(foreach path, $(INC_PATHS), -I $(path))
LFLAGS		=	$(foreach path, $(LIB_PATHS), -L $(path)) \
				$(foreach lib, $(LIB), -l $(lib))
LFLAGS		+=	-lm -lXext -lX11

# ******************************* DIRS AND PATHS ***************************** #

LIB_DIR		=	lib/libft lib/minimath
MLX_DIR		=	lib/minilibx-linux

LIB_PATHS	=	$(LIB_DIR) $(MLX_DIR)

SRC_SUBDIRS	=	debug \
				display \
				event \
				math_utils \
				parsing \
				rendering \
				struct \
				utils

INC_DIR		=	includes
SRC_DIR		=	src
OBJ_DIR		=	obj

INC			=	$(addprefix $(INC_DIR)/, $(INC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

INC_PATHS	=	$(INC_DIR) $(MLX_DIR) \
				$(addsuffix /$(INC_DIR), $(LIB_DIR))

VPATH		=	$(SRC_DIR) $(addprefix $(SRC_DIR)/, $(SRC_SUBDIRS)) \
				$(LIB_PATHS)

# *********************************** LIB ************************************ #

LIB			=	ft minimath mlx_Linux

# ********************************** FILES *********************************** #

INC_FILES	=	minirt.h					\
				minirt_camera.h				\
				minirt_debug.h				\
				minirt_define.h				\
				minirt_env.h				\
				minirt_events.h				\
				minirt_exit.h				\
				minirt_light.h				\
				minirt_math_utils.h			\
				minirt_objects.h			\
				minirt_parsing.h			\
				minirt_ray.h				\
				minirt_render.h				\
				minirt_save.h				\

SRC			=	main.c						\
				check_max_display.c			\
				check_null_light.c			\
				check_null_vector.c			\
				get_hit_point.c				\
				get_pixel_coord.c			\
				get_obj_color.c				\
				get_specular.c				\
				hit.c						\
				hit_cylinder.c				\
				hit_plane.c					\
				hit_sphere.c				\
				hit_square.c				\
				hit_triangle.c				\
				look_at.c					\
				parsing.c					\
				parsing_ambient.c			\
				parsing_cam.c				\
				parsing_light.c				\
				parsing_obj.c				\
				parsing_objadd.c			\
				parsing_resolution.c		\
				parsing_values.c			\
				parsing_utils.c				\
				put_pixel.c					\
				render.c					\
				rescale_color.c				\
				set_ray_dir.c				\
				set_ray_origin.c			\
				trace_ray.c					\
				trace_ray_to_lights.c		\
				trace_ray_to_objs.c			\

# MATH UTILS #

SRC			+=	ft_percent.c				\
				get_cylinder_normal.c		\
				get_obj_normal.c			\
				get_quad_coef.c				\
				get_quad_roots.c			\
				get_sphere_normal.c			\
				get_triangle_normal.c		\

# DISPLAY AND EVENT HANDLING #

SRC			+=	dispatch_events.c			\
				display_render.c			\
				handle_key.c				\
				open_window.c				\
				put_image_to_window.c		\
				reload_image.c				\
				run_loop.c					\
				switch_cam.c				\

# STRUCTS #

SRC			+=	ambient.c					\
				camera.c					\
				image.c						\
				lights.c					\
				lstimg.c					\
				minirt_env.c				\
				objects.c					\
				ray.c						\
				resolution.c				\

# UTILS #

SRC			+=	check_params.c				\
				exit.c						\
				print_error.c				\
				save_bmp.c					\

# DEBUG #

SRC			+=	map_normal2.c				\
				map_normal2_rev.c			\
				map_normal.c

# ********************************** RULES *********************************** #

.PHONY: all
all: $(NAME)

# INSTALL #

.PHONY: install
install :
	#sudo apt-get update && apt-get install libxext-dev libbsd-dev
	@$(foreach dir, $(LIB_PATHS), make -C $(dir);)

.PHONY: re-install
re-install :
	@make -C lib/libft fclean
	@make -C lib/minimath fclean
	@make -C lib/minilibx-linux clean
	@make install

$(NAME): $(OBJ_DIR) $(OBJ) $(INC)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@
	@echo "\nOK\t\t$(NAME) is ready"

# OBJ DIR #

$(OBJ_DIR):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_DIR)/%.o : %.c
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# DEBUG #

.PHONY: show
show:
	@echo "VPATH: $(VPATH)"

.PHONY: debug
debug: CFLAGS+=-g3 -fsanitize=address -D DEBUG=1
debug: re

# CLEAN #

.PHONY: clean
clean:
	@make -C lib/libft clean
	@make -C lib/minimath clean
	@$(RM) -rf $(OBJ_DIR)
	@echo "Cleaned\t\tobject files"

.PHONY: fclean
fclean: clean
	@$(RM) -rf $(NAME)
	@echo "Removed\t\t$(NAME)"

.PHONY: re
re: fclean all
