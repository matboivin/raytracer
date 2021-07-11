SRC_FILES	=	main.c

# RENDERING

SRC_FILES	+=	display.c					\
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
				put_pixel.c					\
				render.c					\
				rescale_color.c				\
				set_ray_dir.c				\
				set_ray_origin.c			\
				trace_ray.c					\
				trace_ray_to_lights.c		\
				trace_ray_to_objs.c

# PARSING

SRC_FILES	+=	check_max_display.c			\
				check_null_light.c			\
				check_null_vector.c			\
				parsing.c					\
				parsing_ambient.c			\
				parsing_cam.c				\
				parsing_light.c				\
				parsing_obj.c				\
				parsing_objadd.c			\
				parsing_resolution.c		\
				parsing_values.c			\
				parsing_utils.c				\

# MATH UTILS

SRC_FILES	+=	get_normal.c				\
				get_quad_coef.c				\
				get_quad_roots.c

# EVENT HANDLING

SRC_FILES	+=	dispatch_events.c			\
				handle_key.c				\
				run_loop.c

# STRUCTS

SRC_FILES	+=	ambient.c					\
				camera.c					\
				image.c						\
				image_list.c				\
				lights.c					\
				minirt_env.c				\
				objects.c					\
				ray.c						\
				resolution.c

# UTILS

SRC_FILES	+=	check_params.c				\
				ft_percent.c				\
				exit.c						\
				save_bmp.c

# DEBUG

SRC_FILES	+=	map_normal2.c				\
				map_normal2_rev.c			\
				map_normal.c
