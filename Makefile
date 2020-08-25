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

SRC			=	main.c						\
				application.c				\
				camera.c					\
				check_max_display.c			\
				check_null_vector.c			\
				check_params.c				\
				create_circular_lstcam.c	\
				dispatch_event.c			\
				display_render.c			\
				exit.c						\
				get_angle_in.c				\
				get_quad_coef.c				\
				get_quad_roots.c			\
				get_cylinder_normal.c		\
				get_hit_point.c				\
				get_obj_normal.c			\
				get_obj_color.c				\
				get_sphere_normal.c			\
				get_triangle_normal.c		\
				handle_key.c				\
				illuminate.c				\
				image.c						\
				hit.c						\
				hit_cylinder.c				\
				hit_plane.c					\
				hit_sphere.c				\
				hit_square.c				\
				hit_triangle.c				\
				lights.c					\
				look_at.c					\
				objects.c					\
				open_window.c				\
				parsing.c					\
				parsing_ambient.c			\
				parsing_cam.c				\
				parsing_light.c				\
				parsing_obj.c				\
				parsing_objadd.c			\
				parsing_resolution.c		\
				parsing_values.c			\
				parsing_utils.c				\
				put_error.c					\
				put_image_to_window.c		\
				put_pixel.c					\
				reload_image.c				\
				render.c					\
				rescale_color.c				\
				save_bmp.c					\
				scene.c						\
				set_ray_dir.c				\
				set_ray_origin.c			\
				shade.c						\
				switch_cam.c				\
				trace_ray.c					\

OBJ			=	$(addprefix $(OBJ_PATH)/, $(SRC:%.c=%.o))

.PHONY: all
all: $(NAME)

.PHONY: install
install :
	@$(foreach dir, $(LIB_PATH), make -C $(dir);)

.PHONY: re-install
re-install :
	@make -C lib/libft fclean
	@make -C lib/minimath fclean
	@make -C lib/mlx clean
	@make install

$(NAME): install $(OBJ_PATH) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@
	@echo "\nOK\t\t$(NAME) is ready"

$(OBJ_PATH):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

$(OBJ_PATH)/%.o : %.c
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: debug
debug: CFLAGS+=-g3 -fsanitize=address
debug: re
	./miniRT scenes/scene.rt

.PHONY: bonus
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
