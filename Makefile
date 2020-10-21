NAME := miniRT

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .c .o .h

# ********************************* INCLUDES ********************************* #

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
				minirt_save.h

# ********************************* C FILES ********************************** #

SRC_FILES	=	main.c						\
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
				trace_ray_to_objs.c

# MATH UTILS #

SRC_FILES	+=	ft_percent.c				\
				get_cylinder_normal.c		\
				get_obj_normal.c			\
				get_quad_coef.c				\
				get_quad_roots.c			\
				get_sphere_normal.c			\
				get_triangle_normal.c

# DISPLAY AND EVENT HANDLING #

SRC_FILES	+=	dispatch_events.c			\
				display_render.c			\
				handle_key.c				\
				open_window.c				\
				put_image_to_window.c		\
				reload_image.c				\
				run_loop.c					\
				switch_cam.c

# STRUCTS #

SRC_FILES	+=	ambient.c					\
				camera.c					\
				image.c						\
				image_list.c				\
				lights.c					\
				minirt_env.c				\
				objects.c					\
				ray.c						\
				resolution.c

# UTILS #

SRC_FILES	+=	check_params.c				\
				exit.c						\
				print_error.c				\
				save_bmp.c

# DEBUG #

SRC_FILES	+=	map_normal2.c				\
				map_normal2_rev.c			\
				map_normal.c

# ********************************* OBJECTS ********************************** #

OBJ_FILES	=	$(SRC_FILES:%.c=%.o)

# *********************************** LIBS *********************************** #

LIBS		=	ft minimath mlx_Linux m Xext X11

# ****************************** DIRS AND PATHS ****************************** #

LIB_DIR		=	lib/libft lib/minimath
MLX_DIR		=	lib/minilibx-linux

INC_DIR		=	includes
SRC_DIR		=	src
OBJ_DIR		=	obj

SUB_DIRS	=	debug \
				display \
				event \
				math_utils \
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

CFLAGS		=	-Wall -Wextra -Werror -g3
CPPFLAGS	=	$(foreach path, $(INC_PATHS), -I $(path))
LDFLAGS		=	$(foreach path, $(LIB_PATHS), -L $(path))
LDLIBS		=	$(foreach lib, $(LIBS), -l $(lib))

# ********************************** RULES *********************************** #

all: $(NAME)

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

$(OBJ_DIR)/%.o : %.c
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ_DIR) $(OBJ) $(INC)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "\nOK\t\t$(NAME) is ready"

# DEBUG #

show:
	@echo "VPATH: $(VPATH)"
	@echo "INC_PATHS: $(INC_PATHS)"
	@echo "LIB_PATHS: $(LIB_PATHS)"

debug: CFLAGS += -DDEBUG=1 -fsanitize=address
debug: re

# CLEAN #

clean:
	@$(foreach lib, $(LIB_DIR), make -C $(lib) clean;)
	@$(RM) -rf $(OBJ_DIR)
	@echo "Cleaned\t\tobject files"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "Removed\t\t$(NAME)"

re: fclean all

.PHONY: all install re-install show debug clean fclean re
