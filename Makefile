NAME := miniRT

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .c .o .h

# ******************************** CC AND FLAGS ****************************** #

CC = gcc

CFLAGS		=	-Wall -Wextra -Werror -g3
IFLAGS		=	$(foreach path, $(INC_PATHS), -I $(path))
LFLAGS		=	$(foreach path, $(LIB_PATHS), -L $(path)) \
				$(foreach lib, $(LIB), -l $(lib))

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

VPATH		=	$(SRC_DIR) $(addprefix $(SRC_DIR)/, $(SRC_SUBDIRS))

# *********************************** LIB ************************************ #

LIB			=	ft minimath mlx_Linux m Xext X11

# ********************************** FILES *********************************** #

INC_FILES	=	minirt.h					\
				minirt_debug.h				\
				minirt_define.h				\
				minirt_env.h				\
				minirt_events.h				\
				minirt_exit.h				\
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
				image_list.c				\
				lights.c					\
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

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(INC)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@
	@echo "\nOK\t\t$(NAME) is ready"

# INSTALL #

install :
	#sudo apt-get update && apt-get install libxext-dev libbsd-dev
	@$(foreach path, $(LIB_PATHS), make -C $(path);)

re-install :
	@make -C lib/libft fclean
	@make -C lib/minimath fclean
	@make -C lib/minilibx-linux clean
	@make install

# OBJ DIR #

$(OBJ_DIR):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_DIR)/%.o : %.c
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# DEBUG #

show:
	@echo "VPATH: $(VPATH)"

debug: CFLAGS+=-fsanitize=address -D DEBUG=1
debug: re

# CLEAN #

clean:
	@make -C lib/libft clean
	@make -C lib/minimath clean
	@$(RM) -rf $(OBJ_DIR)
	@echo "Cleaned\t\tobject files"

fclean: clean
	@$(RM) $(NAME)
	@echo "Removed\t\t$(NAME)"

re: fclean all

.PHONY: all install re-install show debug clean fclean re
