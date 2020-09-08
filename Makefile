NAME = miniRT

SHELL = /bin/sh
CC = gcc
RM = rm -rf

CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address
IFLAGS		=	$(foreach dir, $(INC_PATH), -I $(dir))
LFLAGS		=	$(foreach dir, $(LIB_PATH), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib))
LFLAGS		+=	-lm -lXext -lX11

.SUFFIXE:
.SUFFIXES: .c .o .h

LIB_PATH	=	lib/libft lib/minimath lib/mlx
INC_PATH	=	$(shell find includes -type d) \
				lib/libft/includes lib/minimath/includes lib/mlx
SRC_PATH	=	$(shell find src -type d)
OBJ_PATH	=	obj

vpath %.c $(foreach dir, $(SRC_PATH), $(dir):)

LIB			=	ft minimath mlx_Linux

INC_FILES	=	minirt_camera.h				\
				minirt_debug.h				\
				minirt_define.h				\
				minirt_display.h			\
				minirt_env.h				\
				minirt_events.h				\
				minirt_exit.h				\
				minirt.h					\
				minirt_light.h				\
				minirt_math_utils.h			\
				minirt_objects.h			\
				minirt_parsing.h			\
				minirt_ray.h				\
				minirt_render.h				\
				minirt_save.h				\

INC			=	$(addprefix includes/, $(INC_FILES))

SRC			=	main.c						\
				check_max_display.c			\
				check_null_light.c			\
				check_null_vector.c			\
				get_hit_point.c				\
				get_pixel_coord.c			\
				get_obj_color.c				\
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

# Math utils

SRC			+=	get_cylinder_normal.c		\
				get_obj_normal.c			\
				get_quad_coef.c				\
				get_quad_roots.c			\
				get_sphere_normal.c			\
				get_triangle_normal.c		\

# Display and event handling

SRC			+=	dispatch_event.c			\
				display_render.c			\
				handle_key.c				\
				open_window.c				\
				put_image_to_window.c		\
				reload_image.c				\
				switch_cam.c				\

# Utils

SRC			+=	check_params.c				\
				exit.c						\
				put_error.c					\
				save_bmp.c					\

# Structs

SRC			+=	ambient.c					\
				camera.c					\
				image.c						\
				lights.c					\
				lstimg.c					\
				minirt.c					\
				objects.c					\
				ray.c						\
				resolution.c				\

# Debug

SRC			+=	color_map.c					\
				color_normals.c				\
				color_rev_normals.c			\

# Bonus

SRC			+=	get_specular.c				\

OBJ			=	$(addprefix $(OBJ_PATH)/, $(SRC:%.c=%.o))

.PHONY: all
all: $(NAME)

.PHONY: install
install :
	sudo apt-get update && apt-get install libxext-dev libbsd-dev
	@$(foreach dir, $(LIB_PATH), make -C $(dir);)

.PHONY: re-install
re-install :
	@make -C lib/libft fclean
	@make -C lib/minimath fclean
	@make -C lib/mlx clean
	@make install

$(NAME): $(OBJ_PATH) $(OBJ) $(INC)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@
	@echo "\nOK\t\t$(NAME) is ready"

$(OBJ_PATH):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

$(OBJ_PATH)/%.o : %.c
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: debug
debug: CFLAGS+=-g3 -fsanitize=address -D DEBUG=1
debug: re

.PHONY: bonus
bonus: fclean
bonus: CFLAGS+=-D BONUS=1
bonus: $(NAME)

.PHONY: clean
clean:
	@$(RM) $(OBJ_PATH)
	@echo "Cleaned\t\tobject files"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo "Removed\t\t$(NAME)"

.PHONY: re
re: fclean all
